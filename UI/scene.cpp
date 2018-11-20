#include <QGraphicsSceneMouseEvent>
#include "QGraphicsScene"
#include "ostream"
#include "QPainter"
#include "scene.hh"

Scene::Scene(GameBoard* board, QObject* parent):
    QGraphicsScene(parent), board_(board)
{

}

Scene::~Scene()
{

}

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{

    QGraphicsScene::mouseDoubleClickEvent(event);
    std::cout << "oi suomi on" << std::endl;

    QPoint clickPosition = event->scenePos().toPoint();
    emit mouseClick(clickPosition.x(), clickPosition.y());
}

void Scene::click(int clickX, int clickY)
{

  //  for (const auto& hexi : board_->HexMap){
   //     std::cout << "huu"  << std::endl;
   //     std::cout << board_->getHex(hexi.first) << std::endl;
    //    if (board_->wasClicked(board_->getHex(hexi.first), clickX, clickY) == true){
    //        std::cout << hexi.second << std::endl;
    //    }
    //    }
   // std::cout << "Click coordinates: x=" << clickX << " y=" << clickY << std::endl;
    std::cout << board_->findClickedHex(clickX,clickY).x;
                 //.get()->getCoordinates().x << std::endl;
  //  runnerptr_.get()->flipTile(board_->findClickedHex(clickX,clickY).get()->getCoordinates());



}
