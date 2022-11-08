import QtQuick
import QtQuick.Window


Window
{
    width: 300 ; height: 150 ; color: "grey"
    visible: true
    title: qsTr("Example")

    property var d: Array()

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

    // Mise à jour du modèle de données de la page
    function update_data()
    {
        if (backend != null)
        {
            d = JSON.parse(backend.get_json()); // Vient sous forme de JSON texte depuis le backend C++
        }
    }

    // Mise à jour périodique
    Timer
    {
        id: refresh
        repeat: true
        triggeredOnStart: true
        interval: 500
        onTriggered: update_data();
    }

    // Le rafraichissement débute à la construction de la page
    Component.onCompleted:
    {
        refresh.start();
    }
}
