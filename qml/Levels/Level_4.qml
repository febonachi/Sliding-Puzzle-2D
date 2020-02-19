import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 4
    rows: 3
    columns: 4
    difficulty: 15
    hints:
        [Game.BackgroundFeather,
        Game.BackgroundSun,
        Game.BackgroundUmbrella,
        Game.BackgroundPizza,

        Game.Empty,
        Game.BackgroundLeaf,
        Game.BackgroundCactus,
        Game.BackgroundApple,


        Game.BackgroundCat,
        Game.BackgroundCloud,
        Game.BackgroundTree,
        Game.BackgroundTurtle
    ]
}
