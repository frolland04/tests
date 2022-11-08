import QtQuick
import QtQuick.Window


Window
{
    width: 300 ; height: 150 ; color: "grey"
    visible: true
    title: qsTr("Example")

    ListModel
    {
        id: data
        ListElement { prop_name: "a" ; prop_value: "50"     ; desc: "none" }
        ListElement { prop_name: "b" ; prop_value: "5"      ; desc: "none" }
        ListElement { prop_name: "c" ; prop_value: "2.2512" ; desc: "none" }
        ListElement { prop_name: "d" ; prop_value: "x"      ; desc: "none" }
    }

    Component
    {
        id: render_data

        Row
        {
            Text
            {
                width: 100 ; height: 30 ; color: "blue"
                text: model.prop_name
            }

            Text
            {
                width: 200 ; height: 30 ; color: "lightblue"
                text: model.prop_value
            }
        }
    }

    ListView
    {
        spacing: 10
        anchors.fill: parent

        delegate: render_data
        model: data
    }
}
