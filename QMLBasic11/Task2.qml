import QtQuick 2.0

Item {
    id:root
    anchors.fill:parent

    Rectangle
    {
        id:parentRect
        width: root.width
        height: root.height
        color:"grey"
    }
    Rectangle
    {
        id:childRect
        anchors.centerIn: parentRect
        color:"blue"
        width: parentRect.width - 5;
        height: parentRect.height - 5;
        MouseArea
        {
            id:area
            anchors.fill:parent
            onClicked: {console.log("clicked on inner rect!!")}
        }
    }

}
