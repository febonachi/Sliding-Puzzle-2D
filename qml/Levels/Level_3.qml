import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 3
    rows: 3
    columns: 3
    difficulty: 15
    hints:
        [Game.BackgroundBird,
        Game.BackgroundUmbrella,
        Game.BackgroundCat,

        Game.Empty,
        Game.BackgroundCactus,
        Game.BackgroundFlower,

        Game.BackgroundTree,
        Game.BackgroundTurtle,
        Game.BackgroundApple
    ]
}
