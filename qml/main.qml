import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2

import "."

ApplicationWindow {
    id: root
    visible: true
    visibility: Window.FullScreen
//    x: 1000; y: 40;
//    width: 540; height: 960;

    MainScreen {
        anchors.fill: parent
    }
}
