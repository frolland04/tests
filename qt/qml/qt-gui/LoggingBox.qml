import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2


Rectangle
{
    id: log

    function send(s)
    {
        content.text += s + '\n' ;
        view.move_to_bottom();
    }
    
    width: parent.width - 50 ; height: 200
    color: "white"
    border.width: 3 ; radius: 8

    ScrollView
    {
        id: view
        clip: true
        anchors.fill: parent

        TextArea
        {
            id: content
            padding: 5
            text: "... "
            wrapMode: Text.WrapAnywhere
        }

        function move_to_bottom()
        {
            ScrollBar.vertical.setPosition(0.6);
        }
    }

    Component.onCompleted:
    {
        log.send("STARTED.") ;
    }
}
