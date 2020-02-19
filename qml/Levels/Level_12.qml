import QtQuick 2.9

import CppItems 0.1

Level {
    id: root
    levelId: 12
    rows: 5
    columns: 4
    difficulty: 25
    hints:
        [Game.BackgroundMedusa,
        Game.BackgroundSoda,
        Game.Empty,
        Game.BackgroundPlant,

        Game.BackgroundBug,
        Game.BackgroundCactus,
        Game.BackgroundIcecream,
        Game.BackgroundBagel,

        Game.BackgroundCloud,
        Game.BackgroundPawprint,
        Game.BackgroundCandle,
        Game.BackgroundPeach,

        Game.BackgroundApple,
        Game.BackgroundBird,
        Game.BackgroundBear,
        Game.BackgroundGlasses,

        Game.BackgroundEye,
        Game.BackgroundTree,
        Game.BackgroundStrawberry,
        Game.BackgroundUmbrella
    ]
}
