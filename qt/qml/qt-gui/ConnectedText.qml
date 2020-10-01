import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1


Rectangle
{
    id: connected_text

    property string text: "1"
    property string name: "..."

    width: 300 ; height: 30

    Text
    {
        id: ct
        text: connected_text.name + " : " + connected_text.text

        wrapMode: Text.WrapAnywhere

        anchors.fill: parent
        anchors.centerIn: parent
    }
}
