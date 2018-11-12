#include "actorfactory.hh"
#include "gameengine.hh"
#include "hex.hh"
#include "actor.hh"
#include "illegalmoveexception.hh"
#include "piecefactory.hh"
#include "transportfactory.hh"

#include <algorithm>

namespace Logic {

//! Rule for max pawns per tile
int const MAX_PAWNS_PER_HEX = 3;

GameEngine::GameEngine(std::shared_ptr<Common::IGameBoard> boardPtr,
                       std::shared_ptr<Common::IGameState> statePtr,
                       std::vector<std::shared_ptr<Common::IPlayer> > players):
    playerVector_(players),
    board_(boardPtr),
    gameState_(statePtr)
{
    PieceFactory::getInstance().readJSON();

    initializeBoard();
    layoutParser_.readJSON("Assets/layout.json");
}

int GameEngine::movePawn(Common::CubeCoordinate origin,
                         Common::CubeCoordinate target,
                         int pawnId)
{
    int movesLeft = checkPawnMovement(origin, target, pawnId);
    if (movesLeft < 0 || board_->getHex(origin)->givePawn(pawnId) == 0)
    {
        throw Common::IllegalMoveException("Illegal pawn move");
    } else {
        board_->movePawn(pawnId, target);
    }

    return movesLeft;
}


int GameEngine::checkPawnMovement(Common::CubeCoordinate origin,
                                  Common::CubeCoordinate target,
                                  int pawnId)
{

    // Move is illegal (return -1), if:
    //    (1) Source-, target-hex or pawn doesn't exist
    //    (2) Pawn is not on source-hex
    //    (3) targetHex is occupied (full, max pawns per tile is 3)
    //    (4) distance > moves left
    //    (5) distance != 1 if moving in water
    //    (6) No possible route to target found

    std::shared_ptr<Common::Hex> sourceHex = board_->getHex(origin);
    std::shared_ptr<Common::Hex> targetHex = board_->getHex(target);

    // (1)

    if (sourceHex == nullptr || targetHex == nullptr) {
        return -1;
    }

    // (2)
    std::shared_ptr<Common::Pawn> pawn = sourceHex->givePawn(pawnId);
    if (pawn == nullptr) {
        return -1;
    }

    // (3)
    if (targetHex->getPawnAmount() >= MAX_PAWNS_PER_HEX) {
        return -1;
    }

    unsigned int distance = cubeCoordinateDistance(origin, target);

    int playerId = pawn->getPlayerId();
    if (playerId == gameState_->currentPlayer()) {

        // Find ptr to player
        auto playerIt = playerVector_.begin();
        while (playerIt != playerVector_.end()) {
            if ((*playerIt)->getPlayerId() == gameState_->currentPlayer()) {
                break;
            }
            ++playerIt;
        }

        // (4)
        if ((*playerIt)->getActionsLeft() >= distance) {
            if (board_->isWaterTile(origin) > 0) {
                // (5)
                if (distance == 1) {
                    return 0;
                }
            } else {
                // (6)
                if (breadthFirst(origin,target,
                                (*playerIt)->getActionsLeft())) {
                    unsigned int hadActions = (*playerIt)->getActionsLeft();
                    return hadActions - distance;
                }
            }
        }
    }

    return -1;

}

void GameEngine::moveActor(Common::CubeCoordinate origin,
                           Common::CubeCoordinate target,
                           int actorId,
                           std::string moves)
{
    bool validMove = checkActorMovement(origin, target, actorId,
                                        moves);

    if (!validMove) {
        throw Common::IllegalMoveException("Illegal actor move");
    } else
    {
        board_->moveActor(actorId, target);
    }


}

bool GameEngine::checkActorMovement(Common::CubeCoordinate origin,
                                    Common::CubeCoordinate target,
                                    int actorId,
                                    std::string moves)
{
    // Move is illegal (return false), if:
    //    (1) Source-, target-hex or actor doesn't exist
    //    (2) Actor is not on source-hex
    //    (3) Target-hex is not a water tile
    //    (4) Target-hex is too far away

    // (1)
    std::shared_ptr<Common::Hex> sourceHex = board_->getHex(origin);
    std::shared_ptr<Common::Hex> targetHex = board_->getHex(target);
    if (sourceHex == nullptr || targetHex == nullptr) {
        return false;
    }

    // (2)
    std::shared_ptr<Common::Actor> actor = sourceHex->giveActor(actorId);
    if (actor == nullptr) {
        return false;
    }

    // (3)
    if (!targetHex->isWaterTile()) {
        return false;
    }

    // (4)
    bool distancePass = false;
    unsigned int numMoves = 0;
    if (moves == "D") {
        // Actor can dive any distance
        distancePass = true;
    } else {

        try {
            numMoves = std::stoi(moves);
        } catch(...) {
            // Given moves-argument couldn't be translated to int
            distancePass = false;
            numMoves = 0;
        }

        if (cubeCoordinateDistance(origin, target) <= numMoves) {
            distancePass = true;
        }
    }
    if (!distancePass){
        return false;
    }

    return true;
}

std::string GameEngine::flipTile(Common::CubeCoordinate tileCoord)
{

    gameState_->changeGamePhase(Common::GamePhase::SINKING);

    // Haetaan ko. saaripala ja tarkistetaan sen olemassaolo.
    std::shared_ptr<Common::Hex> currentHex = board_->getHex(tileCoord);
    if (currentHex == nullptr) {
        throw Common::IllegalMoveException("The tile does not exist.");
    }
    std::string pieceType = currentHex->getPieceType();

    // Vesi- ja maaliruutuja ei voi olla mahdollista kääntää.
    if (pieceType == "Water") {
        throw Common::IllegalMoveException("Can not flip the water tile.");
    } else if (pieceType == "Coral") {
        throw Common::IllegalMoveException("Can not flip the coral tile.");
    }

    // Noudatetaan poistojärjestystä: ranta, metsä, vuoristo.

    auto& currentLayer = islandPieces_.back();
    if( pieceType != currentLayer.first ) {
        throw Common::IllegalMoveException("All tiles of type " +
                                           currentLayer.first +
                                           " have not yet been flipped.");
    }

    // Laskurin päivitys.
    --currentLayer.second;
    if (currentLayer.second == 0) {
      islandPieces_.pop_back();

    }

    // Toimijan arvontaa.
    auto actors = Logic::ActorFactory::getInstance().getAvailableActors();
    auto transports = Logic::TransportFactory::getInstance().getAvailableTransports();


    std::vector<std::string> creatables;
    creatables.reserve(actors.size() + transports.size());
    creatables.insert(creatables.end(), actors.begin(), actors.end());
    creatables.insert(creatables.end(), transports.begin(), transports.end());
    std::random_shuffle(creatables.begin(), creatables.end());
    auto selected = creatables.back();

    auto matchString = [selected](auto a)->bool{return a == selected;};
    if(std::find_if(transports.begin(), transports.end(), matchString) != transports.end()){
        board_->addTransport(Logic::TransportFactory::getInstance().createTransport(selected), tileCoord);
    } else if (std::find_if(actors.begin(), actors.end(), matchString) != actors.end()) {
        board_->addActor(ActorFactory::ActorFactory::getInstance().createActor(selected), tileCoord);
    }
    // Asetetaan aiempi arvottu toimija...
    //currentHex->addActor(randActor); // FIXME: should create appropriate actor-objects
    // ...ja muutetaan ruutu vesiruuduksi.
    currentHex->setPieceType("Water");

    return selected;

}

std::pair<std::string,std::string> GameEngine::spinWheel()
{

    gameState_->changeGamePhase(Common::GamePhase::SPINNING);

    // Mikä eläin (arvonta)...
    layoutParser_.getSections();
    std::vector<std::string> sections = layoutParser_.getSections();;
    std::random_shuffle(sections.begin(),sections.end());
    std::string toMove = sections.back();

    // ...ja paljon liikkuu (1,2,3,D -> arvonta).

    auto moves = layoutParser_.getChangesForSection(toMove);
    std::random_shuffle(moves.begin(),moves.end());
    std::string moveAmount = moves.back().first;

    return std::pair<std::string,std::string> (toMove, moveAmount);

}

bool GameEngine::breadthFirst(Common::CubeCoordinate FromCoord, Common::CubeCoordinate ToCoord, unsigned int actionsLeft)
{

    unsigned int currentIndex = 0;
    std::vector<std::pair<Common::CubeCoordinate,unsigned int>> checkVector;
    std::pair<Common::CubeCoordinate,unsigned int> firstTile = std::make_pair(FromCoord,currentIndex);
    checkVector.push_back(firstTile);

    std::vector<Common::CubeCoordinate> workVector;
    workVector.push_back(FromCoord);

    while(not workVector.empty()){

        Common::CubeCoordinate currentCoord = workVector.at(0);
        workVector.erase(workVector.begin());
        std::shared_ptr<Common::Hex> currentHex = board_->getHex(currentCoord);

        if(currentHex->getPawnAmount() < MAX_PAWNS_PER_HEX
                || currentCoord == FromCoord){
            //Tähän implementoidaan laivalla kulkeminen
            if(!(currentHex)->isWaterTile()){
                unsigned int newIndex = 0;
                while(newIndex < checkVector.size()){
                    if(checkVector.at(newIndex).first == currentCoord){
                        break;
                    }
                    newIndex++;
                }
                currentIndex = newIndex;

                std::vector<Common::CubeCoordinate> neighbourVector = currentHex->getNeighbourVector();
                for(auto neighIt = neighbourVector.begin(); neighIt != neighbourVector.end(); neighIt++){

                    if((*neighIt) == ToCoord){
                        std::pair<Common::CubeCoordinate,int> finalTile = std::make_pair((*neighIt),currentIndex);
                        checkVector.push_back(finalTile);

                        unsigned int nextTile = checkVector.size();
                        std::vector<Common::CubeCoordinate> finalRoadVector;
                        while(nextTile != 0){

                            finalRoadVector.insert(finalRoadVector.begin(),checkVector.at(nextTile - 1).first);
                            nextTile = checkVector.at(nextTile  - 1).second;
                        }
                        //finalRoadVector.push_back(FromCoord);
                        if(finalRoadVector.size() <= actionsLeft){
                            //toimita mainwindowille siirtämistä varten infot, jos tehdään animaatiot
                            return true;
                        }
                        else{
                            return false;
                        }
                    }

                    auto checkerIt = checkVector.begin();
                    bool tileNotVisited = true;
                    while(checkerIt != checkVector.end()){
                        if((*checkerIt).first == (*neighIt)){
                            tileNotVisited = false;
                            break;
                        }
                        checkerIt++;
                    }
                    if(tileNotVisited){
                        std::pair<Common::CubeCoordinate,int> tileToCheck = std::make_pair((*neighIt),currentIndex);
                        checkVector.push_back(tileToCheck);
                        workVector.push_back((*neighIt));
                    }
                }

            }
        }
        currentIndex++;
    }

    return false;

}

std::vector<Common::CubeCoordinate> GameEngine::addHexToBoard(
                            Common::CubeCoordinate coord, std::string pieceType)
{
    /* Method creates a new hex and adds it to board.
     * Also tracks the amount of hexes added to the board in _islandPieces
     * Returns the neighbour-vector of the created hex to be used in algorithms
    */

    // Keep track of piece-types and amounts

    // Find the field in islandPieces tracking the amount of this pieceType
    auto matchType = [pieceType](auto a)->bool{return a.first == pieceType;};
    auto islandPiecesField = std::find_if(islandPieces_.begin(),
                                          islandPieces_.end(), matchType);

    std::shared_ptr<Common::Hex> prevHex = board_->getHex(coord);
    if (prevHex != nullptr) {
        // There's already a hex in this position, for whatever reason.
        // It is going to be replaced.

        std::string prevType = prevHex->getPieceType();
        if (islandPiecesField != islandPieces_.end())
        {
            islandPiecesField->second -= 1;
            if (islandPiecesField->second < 0) islandPiecesField->second = 0;
        }

    } else if (islandPiecesField != islandPieces_.end()) {
        islandPiecesField->second += 1;
    } else if (pieceType != "Water" && pieceType != "Coral") {
        // Water and Coral can't be sunk, so don't push them here.
        // New pieceType, push front for sinking-order
        islandPieces_.push_back({pieceType, 1});

    } else {
        // Do nothing to track the amount of Water and Coral
    }

    // Add the hex
    std::shared_ptr<Common::Hex> newHex = std::make_shared<Common::Hex>();
    newHex->setCoordinates(coord);
    newHex->setPieceType(pieceType);
    board_->addHex(newHex);

    return newHex->getNeighbourVector();
}

void GameEngine::initializeBoard()
{
    /* Method initializes the game board -hexes
     * Pieces to fill the board with are defined in Assets/pieces.json
    */

    // Size (radius) of the goal areas on the edge of the board
    int goalSize = 2;

    // Get pieces from piecefactory
    Logic::PieceFactory pieceFactory = Logic::PieceFactory::getInstance();
    pieceFactory.readJSON(); // TODO: Exception handling?
    typedef std::vector<std::pair<std::string,int>> pieceVector;
    pieceVector pieces =
            pieceFactory.getGamePieces();

    // Generate layers of the island starting from center
    int currentLayer = 0;
    pieceVector::iterator iter = pieces.begin();
    while (iter != pieces.end())
    {

        // Do as many layers as specified for this piece-type
        for (int i = 0; i < iter->second; ++i)
        {
            Common::CubeCoordinate coord;

            // Center-piece
            if (i == 0 && iter == pieces.begin())
            {
                coord = Common::CubeCoordinate(0,0,0);
                addHexToBoard(coord, iter->first);
            }

            // Start from bottom-left corner of the ring and step through
            // neighbours until a closed ring
            coord = Common::CubeCoordinate(-currentLayer, 0, currentLayer);

            for (int j = 0; j < 6; ++j)
            {
                // Looping sides of the ring
                for(int k = 0; k < currentLayer; ++k)
                {
                    std::string type = iter->first;

                    // Place goal-hexes only in corners
                    if (type == "Coral")
                    {
                        if (abs(coord.x) >= goalSize && abs(coord.y) >= goalSize
                            && abs(coord.z) >= goalSize)
                        {
                            // Put water between goal-hexes
                            type = "Water";
                        }
                    }

                    std::vector<Common::CubeCoordinate> neighbours =
                            addHexToBoard(coord, type);
                    // Next tile
                    coord = neighbours.at(j);
                }
            }
            ++currentLayer;
        }
        ++iter;
    }

}

unsigned int GameEngine::cubeCoordinateDistance(Common::CubeCoordinate source, Common::CubeCoordinate target) const
{

    return ((abs(source.x - target.x) + abs(source.y - target.y)
             + abs(source.z - target.z)) / 2);

}

int GameEngine::currentPlayer() const
{

    return gameState_->currentPlayer();

}

Common::GamePhase GameEngine::currentGamePhase() const
{

    return gameState_->currentGamePhase();

}



}
