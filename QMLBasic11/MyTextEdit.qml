import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Rectangle {
    function handleFocus()
    {
       if(textEdit.focus == true)
       {
        root.border.color = "#3682CE"
       }
       else
       {
        root.border.color = "#9B9B9B"
       }
    }
    function setWidth()
    {
        if(textEdit.width + 10 <= root.minWidth)
            return root.minWidth
        else if(textEdit.width + 10 > root.maxWidth)
            return root.maxWidth
        return textEdit.width + 10
    }
    id: root
    property int minWidth: 100
    property int minHeight: 50
    property int maxWidth: 200
    property int maxHeight: 100
    //width: textEdit.width + 10


    x: 30; y:30
    Layout.fillWidth: true
    Layout.minimumWidth: 50
    Layout.preferredWidth: textEdit.contentWidth/4
    Layout.maximumWidth: maxWidth
    height: textEdit.height*2
    color: "white"
    radius: 2
    border.width: 1

    border.color: "#9B9B9B"
    TextInput {
        id: textEdit
        text:""
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        leftPadding: 10
        autoScroll: true
        width: parent.width
        maximumLength: 80
        clip:true

        onFocusChanged:handleFocus();
    }
    MouseArea{
        anchors.fill: parent
        onClicked:
        {
            textEdit.forceActiveFocus();
            console.log("clicked")
        }

    }
}
