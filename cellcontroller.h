#ifndef CELLCONTROLLER_H
#define CELLCONTROLLER_H

#include "game.h"
#include "iqmlcomponentcontroller.h"

class CellController : public QObject, public IQmlComponentController{
    Q_OBJECT

private:
    bool c_canMove;
    Game::CellType c_type;

public:
    explicit CellController(Item = nullptr);

public:
    bool canMove() const;
    Game::CellType type() const;
    void setType(Game::CellType);
    void moveLeft(int);
    void moveRight(int);
    void moveUp(int);
    void moveDown(int);

public:
    virtual void info() const;

private slots:
    void onAnimationStopped();
};

#endif // CELLCONTROLLER_H
