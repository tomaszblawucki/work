import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

Window {
    id:base
    visible: true
    width: 300
    height: 300
    title: qsTr("Hello World")



    Item{
        id:root
        anchors.fill:parent
        function reColorize(){}

        Grid{
            id:buttonsGrid
            columns: 3
            spacing: 0

            MyButton{id:btn1 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn2 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn3 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn4 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn5 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn6;height: root.height/3; width: root.width/3}
            MyButton{id:btn7 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn8 ;height: root.height/3; width: root.width/3}
            MyButton{id:btn9 ;height: root.height/3; width: root.width/3}

            Connections{
                target: btn1
                onButtonPressed: btn2.color = "red"
            }
            Connections{
                target: btn2
                onButtonPressed: btn3.color = "red"
            }

        }
    }
}
