import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    width: 640 ; height: 480
    visible: true

    title: qsTr("QML Image Provider Test")

    Image
    {
        property int frame_index: 0

        id: placeholder
        source: "image://MyImageProvider/MyImage" + frame_index.toString()

        Connections
        {
            target: mip
            onNew_result_available:
            {
                console.log("onNew_result_available");
                placeholder.frame_index++;
            }
        }
    }

}
