#ifndef GRIDCONTROLLER_H
#define GRIDCONTROLLER_H

#include <QObject>
#include <QScreen>
#include <QGuiApplication>

#include "game.h"
#include "utils.h"
#include "level.h"
#include "cellcontroller.h"

class GridController : public QObject, public IQmlComponentController{
    Q_OBJECT

private:
    typedef QVector<CellController *> GridArray;
    typedef QVector<GridArray> GridArray2d;

private:
    GridArray2d c_gridArray2d;
    QVariantList c_hints;

public:
    GridController(Item = nullptr);
    ~GridController();

private:
    void clear();
    void checkIfSolved();
    void swapCells(Index, Index);
    Index cellIndex(Game::CellType) const;
    CellController * createCellController(int = 100) const;
    CellController * atIndex(Index);
    int calculateCellSize() const;

public:
    void loadLevel(Level &, bool = false);
    void moveCellsTo(Game::MoveDirection);

public:
    virtual void info() const;

signals:
    void solved();
    void makeMoveSound();
};

#endif // GRIDCONTROLLER_H
