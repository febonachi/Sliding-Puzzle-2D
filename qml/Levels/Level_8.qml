import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 8
    rows: 5
    columns: 2
    difficulty: 25
    hints:
        [Game.BackgroundBulb,
        Game.BackgroundMushroom,

        Game.BackgroundMedusa,
        Game.BackgroundShell,

        Game.BackgroundStrawberry,
        Game.Empty,

        Game.BackgroundSoda,
        Game.BackgroundDiamond,

        Game.BackgroundPepper,
        Game.BackgroundBug
    ]
}
