#ifndef GAMEPLANE_H
#define GAMEPLANE_H

#include <QQuickItem>
#include <QQmlProperty>
#include <QSoundEffect>
#include <QElapsedTimer>

#include "game.h"
#include "level.h"
#include "gridcontroller.h"
#include "gameresult.h"

class GamePlane : public QQuickItem {
    Q_OBJECT

    Q_PROPERTY(QQuickItem * backgroundGrid READ backgroundGrid WRITE setBackgroundGrid)
    Q_PROPERTY(QQuickItem * foregroundGrid READ foregroundGrid WRITE setForegroundGrid)

private:
    int c_movesCounter;
    QElapsedTimer c_timer;
    GridController *c_backgroundGridController;
    GridController *c_foregroundGridController;
    QQuickItem *c_backgroundGrid;
    QQuickItem *c_foregroundGrid;
    Level *c_currentLevel;

public:
    explicit GamePlane(QQuickItem * = 0);
    ~GamePlane();

private:
    void makeSoundEffect();

public:
    Q_INVOKABLE void restartLevel();
    Q_INVOKABLE void loadLevel(Level *);
    Q_INVOKABLE void flipLeft();
    Q_INVOKABLE void flipRight();
    Q_INVOKABLE void flipUp();
    Q_INVOKABLE void flipDown();

public:
    QQuickItem * backgroundGrid() const;
    void setBackgroundGrid(QQuickItem *);
    QQuickItem * foregroundGrid() const;
    void setForegroundGrid(QQuickItem *);

signals:
    void newLevelOpened(GameResult *result);
    void soundEffect();

public slots:
    void openNewLevel();
};

#endif // GAMEPLANE_H
