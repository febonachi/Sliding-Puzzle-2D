import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 16
    rows: 3
    columns: 6
    difficulty: 30
    hints:
        [Game.Empty,
        Game.BackgroundBird,
        Game.BackgroundFeather,
        Game.BackgroundMushroom,
        Game.BackgroundCloud,
        Game.BackgroundFlower,

        Game.BackgroundPizza,
        Game.BackgroundPepper,
        Game.BackgroundPawprint,
        Game.BackgroundCactus,
        Game.BackgroundMedusa,
        Game.BackgroundSoda,

        Game.BackgroundSun,
        Game.BackgroundTree,
        Game.BackgroundTurtle,
        Game.BackgroundDiamond,
        Game.BackgroundBug,
        Game.BackgroundCupcake
    ]
}
