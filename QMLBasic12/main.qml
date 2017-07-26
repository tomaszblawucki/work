import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: 'lightgrey'
GridLayout{
    columns: 2
//    spacing: 6
        Label{text: "Name:"}
        TextInput{id: name; text: "John";}

        Label{text: "Last name:"}
        TextInput{id: surname; text: "Doe"}



        Label{text: "Age:"}
        SpinBox
        {

        }


        Label{text: "Sport:"}
        ComboBox{
            height: 20
            model:["tennis", "football"]
        }

    }
}


