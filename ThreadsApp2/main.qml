import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: root
    visible: true
    height: myProgressBar.height + 10
    title: qsTr("Threading")
    width: (myProgressBar.visible == true) ? myProgressBar.width+10 : result.width+10

    Column
    {
        padding: 5
        ProgressBar{
            id: myProgressBar
            value: myProgress.progress
            visible: (myProgress.progress <= 0.998) ? true : false
            //text: myProgress.getProgress;
            //onDataChanged: value  = backend.progress
        }
        Text{
            id: result
            text: myProgress.result
            visible: (myProgress.progress <= 0.99) ? false : true
        }

    }

}
