import QtQuick 2.12
import QtQuick.Window 2.12


Window
{
    id: main_window

    visible: true
    width: 800 ; height: 600

    color: "#5064fc"
    title: qsTr("Hello World !")


    Item
    {
        id: the_item
        width: 200 ; height: 100

        state: this_nice_control.state

        states: [
            State
            {
                name: "ON"
                PropertyChanges
                {
                    target: this_nice_control
                    width: 160 ; height: 80
                }
            },
            State
            {
                name: "OFF"
                PropertyChanges
                {
                    target: this_nice_control
                    width: 80 ; height: 160
                }
            }
        ]

        Mycontrol
        {
            id: this_nice_control
            anchors.centerIn: parent
        }
    }

    Text
    {
        id: my_text
        anchors.top: the_item.bottom

        text: "coucou! " + the_item.state
    }
}
