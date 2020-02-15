import QtQuick 2.12
import QtQuick.Window 2.12


Rectangle
{
    property bool is_on: false
    id: my_control

    width: 80 ; height: 60
    
    state: (is_on === true) ? "ON" : "OFF"
    
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            console.log("!CLICKED!")
            my_control.is_on = ! my_control.is_on
        }
    }
    
    states: [
        State {
            name: "ON"
            PropertyChanges
            {
                target: my_control
                color: "red"
            }
        },
        State {
            name: "OFF"
            PropertyChanges
            {
                target: my_control
                color: "yellow"
            }
        }
    ]
}
