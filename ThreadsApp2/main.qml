import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: root
    visible: true
    height: myProgressBar.height
    title: qsTr("Threading")

    width: (myProgressBar.visible == true) ? myProgressBar.width : result.width

    Column
    {
        ProgressBar{
            id: myProgressBar
            value: myProgress.progress
            visible: (myProgress.progress <= 0.998) ? true : false
            //text: myProgress.getProgress;
            Component.onCompleted: {
                visible: false;
                console.log("Nested Completed Running!")
            }

            //onDataChanged: value  = backend.progress
        }
        Text{
            id: result
            text: myProgress.name
            visible: (myProgress.progress <= 0.9999) ? false : true

        }

    }

}
