import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import "ajax.js" as AjaxTbx


RoundButton
{
    id: connected_button

    property string button_text: "1"
    property string button_name: "..."

    width: 200 ; height: 60

    Text
    {
        id: ct
        text: connected_button.button_name + " : " + connected_button.button_text

        wrapMode: Text.WrapAnywhere

        anchors.fill: parent
        anchors.centerIn: parent
        anchors.margins: 20
    }
}
