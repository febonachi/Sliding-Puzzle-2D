import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 9
    rows: 3
    columns: 5
    difficulty: 25
    hints:
        [Game.BackgroundCat,
        Game.BackgroundFeather,
        Game.BackgroundIcecream,
        Game.BackgroundEmpty,
        Game.BackgroundPeach,

        Game.BackgroundLeaf,
        Game.BackgroundPizza,
        Game.BackgroundStrawberry,
        Game.BackgroundTurtle,
        Game.BackgroundUmbrella,

        Game.BackgroundMedusa,
        Game.BackgroundPawprint,
        Game.BackgroundPlant,
        Game.BackgroundSoda,
        Game.BackgroundMushroom
    ]
}
