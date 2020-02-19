#include "gameplane.h"

#include <QTime>

#include "settings.h"

extern QString appPath;

/*ctor*/
GamePlane::GamePlane(QQuickItem *parent) : QQuickItem(parent), c_movesCounter(0),
    c_backgroundGridController(nullptr), c_foregroundGridController(nullptr),
    c_backgroundGrid(nullptr), c_foregroundGrid(nullptr), c_currentLevel(nullptr){
}

GamePlane::~GamePlane(){
    delete c_backgroundGridController;
    delete c_foregroundGridController;
}

/*private*/
void GamePlane::makeSoundEffect(){
    c_movesCounter++;
    emit soundEffect();
}

/*public*/
QQuickItem * GamePlane::backgroundGrid() const{
    return c_backgroundGrid;
}

void GamePlane::setBackgroundGrid(QQuickItem *grid){
    delete c_backgroundGridController;
    c_backgroundGrid = grid;
    c_backgroundGrid->setParent(this);
    c_backgroundGrid->setParentItem(this);
    c_backgroundGridController = new GridController(c_backgroundGrid);
}

QQuickItem * GamePlane::foregroundGrid() const{
    return c_foregroundGrid;
}

void GamePlane::setForegroundGrid(QQuickItem *grid){
    delete c_foregroundGridController;
    c_foregroundGrid = grid;
    c_foregroundGrid->setParent(this);
    c_foregroundGrid->setParentItem(this);
    c_foregroundGridController = new GridController(c_foregroundGrid);
    connect(c_foregroundGridController, &GridController::solved, this, &GamePlane::openNewLevel);
    connect(c_foregroundGridController, &GridController::makeMoveSound, this, &GamePlane::makeSoundEffect);
}

/*public Q_INVOKABLE*/
void GamePlane::restartLevel(){
    loadLevel(c_currentLevel);
}

void GamePlane::loadLevel(Level *level){
    c_currentLevel = level;
    c_movesCounter = 0;

    if(c_backgroundGrid && c_foregroundGrid) {
        c_backgroundGridController->loadLevel(*level);

        Level foregroundLevel(*level);
        QVariantList foregroundHints(foregroundLevel.hints());
        std::for_each(foregroundHints.begin(), foregroundHints.end(), [](QVariant &hint){
           hint = QVariant(hint.toInt() + GAME_CELL_TYPE_OFFSET);
        });
        foregroundLevel.setHints(foregroundHints);
        c_foregroundGridController->loadLevel(foregroundLevel, true);

        c_timer.start();
    }
}

void GamePlane::flipLeft(){
    if(c_foregroundGrid) c_foregroundGridController->moveCellsTo(Game::MoveDirection::Left);
}

void GamePlane::flipRight(){
    if(c_foregroundGrid) c_foregroundGridController->moveCellsTo(Game::MoveDirection::Right);
}

void GamePlane::flipUp(){
    if(c_foregroundGrid) c_foregroundGridController->moveCellsTo(Game::MoveDirection::Up);
}

void GamePlane::flipDown(){
    if(c_foregroundGrid) c_foregroundGridController->moveCellsTo(Game::MoveDirection::Down);
}

/*public slots*/
void GamePlane::openNewLevel(){
    Settings settings;
    int newLevelId = c_currentLevel->levelId() + 1;
    if(newLevelId < settings.levelsCount()) settings.setLevelOpened(newLevelId, true);
    GameResult result;
    result.setLevelId(newLevelId);
    result.setMoves(c_movesCounter);
    result.setTime(QTime::fromMSecsSinceStartOfDay(c_timer.elapsed()).toString("mm:ss"));
    emit newLevelOpened(&result);
}
