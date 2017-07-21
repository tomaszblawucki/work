import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Buttons!!!")
    property variant colors: ["blue", "red", "yellow", "green"]




    function getColor()
    {
        return root.colors[Math.ceil(Math.random()*3)]
    }
    function swap()
    {
        var first = b1.color
        console.log("Children color"+grid.childAt(1,1).color)

    }


    GridLayout{
        id:grid
        columns: 3
        anchors.fill:parent
            SecondButton{width: root.width/3;height:root.height/3; id: b1;}
            SecondButton{width: root.width/3;height:root.height/3; id: b2;}
            SecondButton{width: root.width/3;height:root.height/3; id: b3;}
            SecondButton{width: root.width/3;height:root.height/3; id: b4;}
            SecondButton{width: root.width/3;height:root.height/3; id: b5;}
            SecondButton{width: root.width/3;height:root.height/3; id: b6;}
            SecondButton{width: root.width/3;height:root.height/3; id: b7;}
            SecondButton{width: root.width/3;height:root.height/3; id: b8;}
            SecondButton{width: root.width/3;height:root.height/3; id: b9;}

//            MouseArea {
//                id:mouse
//                anchors.fill: parent
//                onPressed: {
//                    console.log("Click grid!");
//                    swap();
//                }
 //   }

}
}
