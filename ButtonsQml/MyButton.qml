import QtQuick 2.0

    Rectangle{
        id:myButton
        signal buttonPressed()


        height: 50
        width: 100
        border.width: 1
        radius: 3
        color: "grey"


        Text{
            anchors.horizontalCenter: myButton.horizontalCenter
            anchors.verticalCenter: myButton.verticalCenter
            text:"button"
        }
        MouseArea{
            anchors.fill:parent
            onPressed: {myButton.color="darkGrey"; myButton.buttonPressed()}
            onReleased:myButton.color="grey"
        }
    }

