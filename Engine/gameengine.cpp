#include "actorfactory.hh"
#include "gameengine.hh"
#include "hex.hh"
#include "illegalmoveexception.hh"
#include "piecefactory.hh"

#include <algorithm>

namespace Logic {

GameEngine::GameEngine(std::shared_ptr<Common::IGameBoard> boardPtr, std::shared_ptr<Common::IGameState> statePtr, std::vector<Common::IPlayer*> playerPtr): _playerVector(playerPtr), _board(boardPtr), _gameState(statePtr) 
{

    ActorFactory::getInstance().readJSON();
    _animalActors = ActorFactory::getInstance().getAnimalActors();
    _commonActors = ActorFactory::getInstance().getCommonActors();

    PieceFactory::getInstance().readJSON();
    _gamePieces = PieceFactory::getInstance().getGamePieces();
    for (auto item = _gamePieces.begin(); item != _gamePieces.end(); item++) {
        if (item->first == "Beach") {
            _beachTilesLeft = item->second;
        } else if (item->first == "Forest") {
            _forestTilesLeft = item->second;
        } else if (item->first == "Mountain") {
            _mountainTilesLeft = item->second;
        }
    }

    initializeBoard();

}

int GameEngine::checkPawnMovement(Common::CubeCoordinate pawnToMove, Common::CubeCoordinate tileToMove, int pawnId)
{

    // Siirto on laiton (palautetaan arvo -1), jos:
    //    (1) ruutu on jo varattu (on siis täynnä)
    //    (2) etäisyys > siirtoja
    //    (3) etäisyys != 1 vesiruudun tapauksessa
    //    (4) ei ollut olemassa reittiä kohteeseen

    // (1)
    if (_board->checkTileOccupation(tileToMove) > 2) {
        return -1;
    }

    unsigned int distance = cubeCoordinateDistance(pawnToMove,tileToMove);

    if (pawnId == _gameState->currentPlayer()) {
        auto playerIt = _playerVector.begin();
        while (playerIt != _playerVector.end()) {
            if ((*playerIt)->getPlayerId() == _gameState->currentPlayer()) {
                break;
            }
            ++playerIt;
        }

        // (2)
        if ((*playerIt)->getActionsLeft() >= distance) {
            if (_board->isWaterTile(pawnToMove) > 0) {
                // (3)
                if (distance == 1) {
                    (*playerIt)->setActionsLeft(0);
                    return (*playerIt)->getActionsLeft();
                }
            } else {
                // (4)
                if (breadthFirst(pawnToMove,tileToMove,
                                (*playerIt)->getActionsLeft())) {
                    unsigned int hadActions = (*playerIt)->getActionsLeft();
                    (*playerIt)->setActionsLeft(hadActions - distance);
                    return (*playerIt)->getActionsLeft();
                }
            }
        }
    }

    return -1;

}

std::string GameEngine::flipTile(Common::CubeCoordinate tileCoord)
{

    _gameState->changeGamePhase(Common::GamePhase::SINKING);

    // Haetaan ko. saaripala ja tarkistetaan sen olemassaolo.
    std::shared_ptr<Common::Hex> currentHex = _board->getHex(tileCoord);
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
    if ((_beachTilesLeft > 0 && pieceType != "Beach")) {
        throw Common::IllegalMoveException("All the beaches have not yet been flipped.");
    } else if ((_forestTilesLeft > 0 && pieceType != "Forest")) {
        throw Common::IllegalMoveException("All the forests have not yet been flipped.");
    } else if ((_mountainTilesLeft > 0 && pieceType != "Mountain")) {
        throw Common::IllegalMoveException("All the mountains have not yet been flipped.");
    }

    // Laskurin päivitys.
    if (pieceType == "Beach") {
        _beachTilesLeft = _beachTilesLeft - 1;
    } else if (pieceType == "Forest") {
        _forestTilesLeft = _forestTilesLeft - 1;
    } else if (pieceType == "Mountain") {
        _mountainTilesLeft = _mountainTilesLeft - 1;
    }

    // Toimijan arvontaa.
    std::vector<std::string> allActors;
    for (auto actor = _animalActors.begin(); actor != _animalActors.end(); actor++) {
        allActors.push_back(*actor);
    }
    for (auto actor = _commonActors.begin(); actor != _commonActors.end(); actor++) {
        allActors.push_back(*actor);
    }
    std::random_shuffle(allActors.begin(),allActors.end());
    std::string randActor = allActors.back();

    // Asetetaan aiempi arvottu toimija...
    currentHex->setActorType(randActor);
    // ...ja muutetaan ruutu vesiruuduksi.
    currentHex->setPieceType("Water");

    return randActor;

}

std::pair<std::string,std::string> GameEngine::spinWheel()
{

    _gameState->changeGamePhase(Common::GamePhase::SPINNING);

    // Mikä eläin (arvonta)...
    std::vector<std::string> animals = _animalActors;
    std::random_shuffle(animals.begin(),animals.end());
    std::string randAnimal = animals.back();

    // ...ja paljon liikkuu (1,2,3,D -> arvonta).
    std::vector<std::string> numbers = {"1", "2", "3", "D"};
    std::random_shuffle(numbers.begin(),numbers.end());
    std::string randNumber = numbers.back();

    return std::pair<std::string,std::string> (randAnimal,randNumber);

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
        std::shared_ptr<Common::Hex> currentHex = _board->getHex(currentCoord);

        if((currentHex)->getPawns() < 3){
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

std::vector<Common::CubeCoordinate> GameEngine::addHexToBoard(Common::CubeCoordinate coord,
                                                   std::string pieceType)
{
    /* Method creates a new hex and adds it to board.
     * Returns the neighbour-vector of the created hex to be used in algorithms
    */
    std::shared_ptr<Common::Hex> newHex = std::make_shared<Common::Hex>();
    newHex->setCoordinates(coord);
    newHex->setPieceType(pieceType);
    _board->addHex(newHex);

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

    return _gameState->currentPlayer();

}

Common::GamePhase GameEngine::currentGamePhase() const
{

    return _gameState->currentGamePhase();

}



}
