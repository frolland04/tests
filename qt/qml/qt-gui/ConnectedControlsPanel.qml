import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtWebSockets 1.0

import "ajax.js" as AjaxTbx


Grid
{
    rows: 4 ; columns: 2
    padding: 10 ; spacing: 20
    
    ConnectedText
    {
        color: "green"
        name: "AJAX_GET"
        text: "1"

        Component.onCompleted:
        {
            log.send("1!");

            AjaxTbx.ajax_get_json('http://localhost:8001', function(obj) {
                log.send("1!!");
                if (obj.title) text = obj.title;
            });
        }
    }

    ConnectedButton
    {
        button_name: "AJAX_POST"
        button_text: "2"

        onClicked:
        {
            log.send("2!");

            AjaxTbx.ajax_post_json('http://localhost:8001', '{ query: "Hello World!" }', function(obj) {
                log.send("2!!");
                if (obj.success) button_text = "SUCCESS!";
            });
        }
    }
    
    ConnectedText
    {
        id: item3
        color: "red"
        text: "3"

        WebSocket
        {
            id: socket
            url: "ws://localhost:8000"
            active: true

            onTextMessageReceived:
            {
                //log.send("[WS] Receiving: " + message);
                var obj = JSON.parse(message);
                item3.text = obj.value
            }

            onStatusChanged:
            {
                if (socket.status == WebSocket.Error)
                {
                    log.send("[WS] ERROR: " + socket.errorString);
                }
                else if (socket.status == WebSocket.Connecting)
                {
                    log.send("[WS] Connecting...");
                }
                else if (socket.status == WebSocket.Open)
                {
                    log.send("[WS] Opened.");
                    socket.sendTextMessage('{ "value": 5000 }');
                }
                else if (socket.status == WebSocket.Closing)
                {
                    log.send("[WS] Closing...");
                }
                else if (socket.status == WebSocket.Closed)
                {
                    log.send("[WS] Closed.");
                }
            }
        }
    }

    ConnectedButton
    {
        id: reset_button
        button_name: "RESET_CMD"
        button_text: "4"
        onClicked: socket.sendTextMessage('{ "value": 0 }');
    }
    
    ConnectedText
    {
        color: "white"
        text: "5"
    }

    ConnectedText
    {
        color: "yellow"
        text: "6"
    }

    ConnectedText
    {
        color: "purple"
        text: "7"
    }
}
