import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 5
    rows: 4
    columns: 3
    difficulty: 15
    hints:
        [Game.BackgroundCupcake,
        Game.BackgroundBagel,
        Game.BackgroundCat,

        Game.BackgroundPepper,
        Game.BackgroundIcecream,
        Game.BackgroundSoda,

        Game.BackgroundBird,
        Game.BackgroundCactus,
        Game.BackgroundDiamond,

        Game.BackgroundPeach,
        Game.BackgroundApple,
        Game.Empty
    ]
}
