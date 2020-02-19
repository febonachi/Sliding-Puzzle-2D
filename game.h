#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QQuickItem>
#include <QQmlEngine>

#include "utils.h"

#define GAME_ORGANIZATION "ROOL APPS"
#define GAME_NAME "Jigsaw Puzzle"
#define GAME_CELL_TYPE_OFFSET 1000
#define GAME_LEVELS_COUNT 23

class Game : public QObject {
    Q_OBJECT

    Q_PROPERTY(QQmlEngine * engine READ engine WRITE setEngine)

public:
    enum MoveDirection {Left, Right, Up, Down};
    enum CellType {Empty = 0,
                   BackgroundBug,
                   BackgroundFlower,
                   BackgroundPepper,
                   BackgroundApple,
                   BackgroundBall,
                   BackgroundBird,
                   BackgroundBagel,
                   BackgroundCactus,
                   BackgroundCat,
                   BackgroundCloud,
                   BackgroundCup,
                   BackgroundCupcake,
                   BackgroundDiamond,
                   BackgroundEye,
                   BackgroundFeather,
                   BackgroundIcecream,
                   BackgroundLeaf,
                   BackgroundMushroom,
                   BackgroundPeach,
                   BackgroundPizza,
                   BackgroundPlant,
                   BackgroundSoda,
                   BackgroundSun,
                   BackgroundTree,
                   BackgroundTurtle,
                   BackgroundUmbrella,
                   BackgroundCandle,
                   BackgroundCandy,
                   BackgroundGlasses,
                   BackgroundBulb,
                   BackgroundMedusa,
                   BackgroundPawprint,
                   BackgroundShell,
                   BackgroundStrawberry,
                   BackgroundBear,
                   Transparent = GAME_CELL_TYPE_OFFSET,
                   ForegroundBug,
                   ForegroundFlower,
                   ForegroundPepper,
                   ForegroundApple,
                   ForegroundBall,
                   ForegroundBird,
                   ForegroundBagel,
                   ForegroundCactus,
                   ForegroundCat,
                   ForegroundCloud,
                   ForegroundCup,
                   ForegroundCupcake,
                   ForegroundDiamond,
                   ForegroundEye,
                   ForegroundFeather,
                   ForegroundIcecream,
                   ForegroundLeaf,
                   ForegroundMushroom,
                   ForegroundPeach,
                   ForegroundPizza,
                   ForegroundPlant,
                   ForegroundSoda,
                   ForegroundSun,
                   ForegroundTree,
                   ForegroundTurtle,
                   ForegroundUmbrella,
                   ForegroundCandle,
                   ForegroundCandy,
                   ForegroundGlasses,
                   ForegroundBulb,
                   ForegroundMedusa,
                   ForegroundPawprint,
                   ForegroundShell,
                   ForegroundStrawberry,
                   ForegroundBear,
                  };
    Q_ENUM(MoveDirection)
    Q_ENUM(CellType)

private:
    static QQmlEngine *c_engine;

public:
    Game(QObject * = 0);

public:
    static QQmlEngine * engine();
    static void setEngine(QQmlEngine *);
    static QQuickItem * createQmlObject(QString const);
    static QString cellTypeAsString(CellType);
    static QString fullImagePath(CellType);

signals:

public slots:
};

#endif // GAMELOGIC_H
