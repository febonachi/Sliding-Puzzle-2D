import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 10
    rows: 5
    columns: 3
    difficulty: 25
    hints:
        [Game.BackgroundApple,
        Game.BackgroundBulb,
        Game.BackgroundFlower,

        Game.BackgroundGlasses,
        Game.BackgroundDiamond,
        Game.BackgroundCup,

        Game.Empty,
        Game.BackgroundCandy,
        Game.BackgroundBird,

        Game.BackgroundBear,
        Game.BackgroundEye,
        Game.BackgroundPawprint,

        Game.BackgroundPeach,
        Game.BackgroundPlant,
        Game.BackgroundShell
    ]
}
