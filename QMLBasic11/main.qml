import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3


Window {
    id:root
    visible: true
    width: 450
    minimumWidth: 400
    maximumWidth: 550
    height: 400
    minimumHeight: 350
    maximumHeight: 450
    title: qsTr("Hello World")
    color: "lightgrey"

    Rectangle{
        id: mainWindow
        color: "transparent"
        width: parent.width - 20
        height: parent.height - 30
        y:20
        x:10
        anchors.top: root

        ColumnLayout{
            width:parent.width
//            height: parent.height
            GridLayout{
                width: parent.width
                columns: 2
                rowSpacing: 10
                columnSpacing: 20

                Label{text: "Name: "}
                //Spacer{_width: 20}
                MyTextEdit{id: nameInput; maxWidth: parent.width - 20}

                Label{text: "Last Name: "}
                // Spacer{_width: 20}
                MyTextEdit{id: surnameInput; maxWidth: parent.width}

                Label{text: "Age: "}
                //Spacer{_width: 20}
                SpinBox{id: ageInput; maximumValue: 99; minimumValue: 1; implicitWidth: 100; horizontalAlignment: Qt.AlignLeft }

                Label{text: "Country: "}
                //Spacer{_width: 20}
                ComboBox{id: countryInput; implicitWidth: parent.width/3; model:["Poland", "Russia", "England"];
                    onCurrentIndexChanged: {console.log("Current index text: "+ countryInput.currentText )} }

            }
            Spacer{height: 10}
            Label{text: "Sports:"}
            Spacer{height: 5}
            GridLayout
            {
                width: parent.width
                columns: 2
                rowSpacing: 10
                columnSpacing: parent.width/3

                CheckBox{text: "football"}
                CheckBox{text: "skating"}
                CheckBox{text: "basketball"}
                CheckBox{text: "heavy weight lifting"}
                CheckBox{text: "hockey"}
                CheckBox{text: "swimming"}
                CheckBox{text: "cricket"}
                CheckBox{text: "running"}
            }

        }
    }

    RowLayout
    {
        anchors.bottom:  mainWindow.bottom
        anchors.right:  mainWindow.right
        spacing: 10
        Spacer{width: parent.width; height:1;}
        Button{text: 'OK'}
        Button{text: 'CANCEL'; anchors.bottom: parent.anchors.baseline}
    }


}



