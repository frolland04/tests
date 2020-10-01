import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import "ajax.js" as Ajax


Grid
{
    rows: 4 ; columns: 2
    padding: 10 ; spacing: 20
    
    ConnectedText
    {
        color: "green"
        name: "AJAX_REST"
        text: "1"

        Component.onCompleted:
        {
            log.send("1!");

            Ajax.ajax_restapi_get_json('http://localhost:8001', function(obj) {
                log.send("1!!");
                text = obj.title;
            });
        }
    }
    
    ConnectedText
    {
        color: "red"
        text: "2"
    }
    
    ConnectedText
    {
        color: "blue"
        text: "3"
    }
    
    ConnectedText
    {
        color: "white"
        text: "4"
    }

    ConnectedText
    {
        color: "yellow"
        text: "5"
    }

    ConnectedText
    {
        color: "purple"
        text: "6"
    }
}
