import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 6
    rows: 4
    columns: 4
    difficulty: 20
    hints:
        [Game.BackgroundBug,
        Game.BackgroundBird,
        Game.BackgroundPeach,
        Game.BackgroundPepper,

        Game.BackgroundMushroom,
        Game.BackgroundLeaf,
        Game.BackgroundPizza,
        Game.Empty,

        Game.BackgroundTurtle,
        Game.BackgroundIcecream,
        Game.BackgroundCup,
        Game.BackgroundGlasses,

        Game.BackgroundCactus,
        Game.BackgroundDiamond,
        Game.BackgroundSun,
        Game.BackgroundApple
    ]
}
