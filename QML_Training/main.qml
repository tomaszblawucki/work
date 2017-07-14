import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id:root
    title: qsTr("Every day LEARN!!")
    width: 640
    height: 480
    visible: true


    Rectangle{
    id: rootComponent
    width: parent.width
    height: parent.height
    color: "#AFDDA6"
    property var lastColor


    function gravity(){
        for(var i = dragableItem; i < 300; i++){
            dragableItem.y = i
        }
    }


    Text{
        id: rootText
        text: "Nice area"
        y:20
        anchors.horizontalCenter: rootComponent.horizontalCenter
        font.pointSize: 30; font.bold: true



        MouseArea{
            id: mouseArea
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
        }

        states: State{
            name: "down"; when: mouseArea.pressedButtons & Qt.RightButton
            PropertyChanges {
                target: rootText; y: rootComponent.height - 50; rotation:0; color: "red"
            }
        }
        transitions: Transition{
            from: ""; to: "down"; reversible: true
            ParallelAnimation{
                NumberAnimation{ properties: "y ,rotation"; duration: 2000; easing.type: Easing.OutSine}
                ColorAnimation{ duration:{from: 2500; to:6000 }}
            }
        }
    }

    Rectangle{
        id:dragableItem
        width: 50; height: 50
        y: 200; x:200
        color: "grey"

        MouseArea{
            anchors.fill:parent
            drag.target: dragableItem
            drag.axis: Drag.XAndYAxis
            drag.minimumX: 0
            drag.maximumX: rootComponent.width - parent.width
            drag.minimumY: 0
            drag.maximumY: rootComponent.height - parent.height
            onReleased: {
                root.gravity()
                console.log("RELEASED")
                dragableItem.y = 20
                }
        }



    }

    Grid{
        id:colorPicker
        x: 4; anchors.bottom: rootComponent.bottom; anchors.bottomMargin: 4
        rows: 2; columns: 3; spacing: 3

        Cell { cellColor: "red"; onClicked: {
                rootComponent.lastColor = rootComponent.color
                rootComponent.color = cellColor
                if(rootComponent.lastColor === rootComponent.color){
                rootText.color = rootComponent.lastColor}
            } }
        Cell { cellColor: "green"; onClicked: {
                rootComponent.lastColor = rootComponent.color
                rootComponent.color = cellColor
                if(rootComponent.lastColor === rootComponent.color){
                rootText.color = rootComponent.lastColor}
            } }
        Cell { cellColor: "blue"; onClicked: {
                rootComponent.lastColor = rootComponent.color
                rootComponent.color = cellColor
                if(rootComponent.lastColor === rootComponent.color){
                rootText.color = rootComponent.lastColor}
            } }
        Cell { cellColor: "yellow"; onClicked: {
                rootComponent.lastColor = rootComponent.color
                rootComponent.color = cellColor
                if(rootComponent.lastColor === rootComponent.color){
                rootText.color = rootComponent.lastColor}
            } }
        Cell { cellColor: "steelblue"; onClicked: {
                rootComponent.lastColor = "pink"
                rootComponent.color = cellColor
                if(rootComponent.lastColor === rootComponent.color){
                rootText.color = rootComponent.lastColor}
            } }
        Cell { cellColor: "black"; onClicked: {
                rootComponent.color = cellColor
            } }
    }

  }
}
