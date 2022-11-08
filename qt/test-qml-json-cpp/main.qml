import QtQuick
import QtQuick.Window


Window
{
    width: 300 ; height: 150 ; color: "grey"
    visible: true
    title: qsTr("Example")

    property var d: backend != null ? [{ prop_name: "a" , prop_value: backend.a },
                                       { prop_name: "b" , prop_value: backend.b },
                                       { prop_name: "c" , prop_value: backend.c },
                                       { prop_name: "d" , prop_value: backend.d }] : null

    Component
    {
        id: render_data

        Row
        {
            Text
            {
                width: 100 ; height: 30 ; color: "blue"
                text: modelData.prop_name
            }

            Text
            {
                width: 200 ; height: 30 ; color: "lightblue"
                text: modelData.prop_value.toString()
            }
        }
    }

    Column
    {
        spacing: 10 ; padding: 10
        anchors.fill: parent

        Repeater
        {
            model: d
            delegate: render_data
        }
    }
}
