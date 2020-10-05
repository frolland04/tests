import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

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
        color: "red"
        text: "3"
    }
    
    ConnectedText
    {
        color: "blue"
        text: "4"
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
