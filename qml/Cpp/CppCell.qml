import QtQuick 2.0
import QtMultimedia 5.9

Item {
    id: root

    property alias source: image.source

    signal animationStopped();

    Image {
        id: image
        objectName: "image"
        sourceSize.width: parent.width
        sourceSize.height: parent.height
        fillMode: Image.PreserveAspectFit
    }

    Behavior on x {
        NumberAnimation {
            id: numberAnimationX
            easing.overshoot: 0.5
            easing.period: 0.5
            easing.amplitude: 1
            easing.type: Easing.InOutSine
            duration: 250

            onRunningChanged: if(!running) animationStopped()
        }
    }

    Behavior on y {
        NumberAnimation {
            id: numberAnimationY
            easing.overshoot: 0.5
            easing.period: 0.5
            easing.amplitude: 1
            easing.type: Easing.InOutSine
            duration: 250

            onRunningChanged: if(!running) animationStopped()
        }
    }
}
