import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 600
    height: 900
    title: qsTr("Waterfall Flow")
    color: "#bbb"

    Canvas {
        id: canvas
        width: 200; height: 200

        property real angle: 0

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)
            ctx.save()
            ctx.translate(width/2, height/2)
            ctx.rotate(angle)
            ctx.fillStyle = "red"
            ctx.fillRect(-50, -50, 100, 100)
            ctx.restore()
        }

        RotationAnimation on angle {
            from: 0; to: 360
            duration: 2000
            loops: Animation.Infinite
        }
    }
}
