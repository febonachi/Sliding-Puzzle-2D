import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 11
    rows: 4
    columns: 5
    difficulty: 25
    hints:
        [Game.BackgroundBagel,
        Game.BackgroundFeather,
        Game.BackgroundLeaf,
        Game.BackgroundMushroom,
        Game.BackgroundPawprint,

        Game.BackgroundCactus,
        Game.BackgroundCandle,
        Game.BackgroundBulb,
        Game.BackgroundPepper,
        Game.BackgroundPizza,

        Game.BackgroundCat,
        Game.BackgroundSoda,
        Game.BackgroundSun,
        Game.BackgroundBird,
        Game.BackgroundCloud,

        Game.BackgroundFlower,
        Game.BackgroundMedusa,
        Game.BackgroundPeach,
        Game.BackgroundDiamond,
        Game.Empty
    ]
}
