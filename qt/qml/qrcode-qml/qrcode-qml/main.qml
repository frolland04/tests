import QtQuick 2.9
import QtQuick.Window 2.2

import QZXing 3.1


Window
{
    visible: true
    width: 800 ; height: 800

    title: qsTr("Hello World")    

    Column
    {
        spacing: 5
        anchors.fill: parent

        Text
        {
            id: input

            width: 800 ; height: 100

            text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit."
            wrapMode: Text.WordWrap
        }

        Image
        {
            /*
            attribute name   value          description
            ------------------------------------------------------------
            border           true, false    image has border (white 1px)
            correctionLevel  L, M, Q, H     the error correction level
            format           qrcode         the encode formatter. Currently only QR Code.
            transparent      true, false    whether the black pixels are transparent
            */

            source: "image://QZXing/encode/" + input.text +
                    "?border=true" +
                    "&correctionLevel=M" +
                    "&format=qrcode" +
                    "&transparent=false"

            sourceSize.width: 600
            sourceSize.height: 600
            cache: false;
        }
    }
}
