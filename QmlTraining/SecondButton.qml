import QtQuick 2.0




Rectangle {

    function getColor()
    {
        return root.colors[Math.ceil(Math.random()*4 -1)]
    }


    id: rootRect
    property int number: 0
    property string title: "Button"
    property string mColor: getColor()
    signal activated(real xPosition, real yPosition)
    width: 100
    height: 100
    border.color: "black"
    radius: 2
    color: mColor
    Text{
        id:text
        text: title
        color: "black"
        anchors.horizontalCenter: rootRect.horizontalCenter
        anchors.verticalCenter: rootRect.verticalCenter

    }
    MouseArea {
        id:mouse
        anchors.fill: parent
        onPressed: {

            rootRect.color = "grey"
            console.log("Click!");
        }
        onReleased: {
            rootRect.color = getColor();
        }
    }
}
