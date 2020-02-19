import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 15
    rows: 6
    columns: 2
    difficulty: 30
    hints:
        [Game.BackgroundUmbrella,
        Game.BackgroundTurtle,

        Game.BackgroundLeaf,
        Game.BackgroundCup,

        Game.BackgroundFeather,
        Game.Empty,

        Game.BackgroundCat,
        Game.BackgroundGlasses,

        Game.BackgroundMushroom,
        Game.BackgroundPeach,

        Game.BackgroundEye,
        Game.BackgroundBear
    ]
}
