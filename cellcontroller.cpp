#include "cellcontroller.h"

extern QString appPath;

/*ctor*/
CellController::CellController(Item object) : IQmlComponentController(object), c_canMove(true), c_type(Game::CellType::Empty){
    connect(c_qmlObject, SIGNAL(animationStopped()), this, SLOT(onAnimationStopped()));
}

/*public*/
bool CellController::canMove() const{
    return c_canMove;
}

Game::CellType CellController::type() const{
    return c_type;
}

void CellController::setType(Game::CellType type){
    write(c_qmlObject, "source", Game::fullImagePath(type));
    c_type = type;
}

void CellController::moveLeft(int offset){
    if(c_canMove){
        write(c_qmlObject, "x", c_qmlObject->x() - (c_qmlObject->width() + offset));
        c_canMove = false;
    }
}

void CellController::moveRight(int offset){
    if(c_canMove){
        write(c_qmlObject, "x", c_qmlObject->x() + (c_qmlObject->width() + offset));
        c_canMove = false;
    }
}

void CellController::moveUp(int offset){
    if(c_canMove){
        write(c_qmlObject, "y", c_qmlObject->y() - (c_qmlObject->height() + offset));
        c_canMove = false;
    }
}

void CellController::moveDown(int offset){
    if(c_canMove){
        write(c_qmlObject, "y", c_qmlObject->y() + (c_qmlObject->height() + offset));
        c_canMove = false;
    }
}

/*public virtual*/
void CellController::info() const{
    dbg << "CELL INFO:";
    return IQmlComponentController::info();
}

/*public slots*/
void CellController::onAnimationStopped(){
    c_canMove = true;
}
