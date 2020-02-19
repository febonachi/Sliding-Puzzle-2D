import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 17
    rows: 6
    columns: 3
    difficulty: 30
    hints:
        [Game.BackgroundTree,
        Game.BackgroundCupcake,
        Game.BackgroundCloud,

        Game.BackgroundCactus,
        Game.BackgroundDiamond,
        Game.BackgroundGlasses,

        Game.BackgroundCandle,
        Game.BackgroundApple,
        Game.BackgroundBall,

        Game.BackgroundPeach,
        Game.BackgroundMushroom,
        Game.BackgroundPizza,

        Game.BackgroundIcecream,
        Game.BackgroundFeather,
        Game.BackgroundSun,

        Game.BackgroundStrawberry,
        Game.Empty,
        Game.BackgroundTurtle
    ]
}
