import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 7
    rows: 2
    columns: 5
    difficulty: 25
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
        Game.BackgroundIcecream
    ]
}
