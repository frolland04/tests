import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2


Window
{
    id: main_window

    width: 800 ; height: 600
    visible: true
    title: qsTr("Hello World QML Test Application...")

    Rectangle
    {
        width: parent.width - 50 ; height: parent.height - 50
        color: "darkgrey"
        border.width: 3 ; radius: 8

        anchors.centerIn: parent

        ConnectedControlsPanel
        {
            anchors.centerIn: parent
        }

        LoggingBox
        {
            id: log
            anchors { bottom: parent.bottom ; horizontalCenter: parent.horizontalCenter }
        }
    }
}
