import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 0
    rows: 2
    columns: 2
    difficulty: 0.2
    hints:
        [Game.BackgroundBug,
        Game.BackgroundFlower,

        Game.BackgroundPepper,
        Game.Empty
    ]
}
