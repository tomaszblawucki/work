import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id:root
    visible: true
    width: 1024
    height: 480
    title: qsTr("Hello World")

    //    Rectangle{
    //        function countUp()
    //        {
    //            button.counter ++;
    //        }
    //        id:button;
    //        property int counter: 0
    //        width: 100
    //        height: 50
    //        color:'lightgrey'
    //        anchors.centerIn: parent
    //        border.color: 'black'
    //        border.width: 1
    //        radius: 3
    //        Text{
    //            text:"click number " + button.counter
    //            anchors.centerIn: button
    //        }
    //        MouseArea{
    //            anchors.fill: parent
    //            onClicked: {button.countUp(); console.log(button.counter)}
    //        }
    //    }

    Rectangle{
        function rotationSpeed(speed)
        {
            wheel.speed = speed*1000;
            console.log("current speed: " + wheel.speed);
        }


        id:wheel;
        property int speed: 0
        property int oldFrom: 0
        width: 200
        height: 200
        y:root.height/2 - wheel.height/2
        color:'lightgrey'
        //anchors.centerIn: parent
        border.color: 'black'
        border.width: 4
        radius: wheel.width/2
        Rectangle
        {
            width:parent.width
            height: 2
            rotation:60
            border.width: 4
            border.color: 'black'
            anchors.left: parent.left
            anchors.centerIn: parent
        }
        Rectangle
        {
            width:parent.width
            height: 2
            rotation:120
            border.width: 4
            border.color: 'black'
            anchors.left: parent.left
            anchors.centerIn: parent
        }
        Rectangle
        {
            width:parent.width
            height: 2
            rotation:180
            border.width: 4
            border.color: 'black'
            anchors.left: parent.left
            anchors.centerIn: parent
        }



        SequentialAnimation on x {
            loops: Animation.Infinite
            PropertyAnimation { from: 0; to: root.width - wheel.width; duration: 2000; easing.type: Easing.InOutSine;}
            PropertyAnimation { from: root.width - wheel.width; to: 0; duration: 2000; easing.type: Easing.InOutSine;}
        }


//        SequentialAnimation on rotation {
//            id:sa
//            loops: Animation.Infinite
//            PropertyAnimation
//            {
//                id: rotationAnim
//                from: 0; to: 360; duration: speedValue.value;

//                onDurationChanged:
//                {
//                    rotationAnim.from = wheel.rotation
//                    rotationAnim.to = wheel.rotation-360
//                    sa.restart()
//                }
//            }
//        }

                RotationAnimation on rotation{

                    function changeDir()
                    {
                        wheelRotation.dir = (-wheelRotation.dir)
                        wheelRotation.from = wheel.rotation
                        wheelRotation.to = wheel.rotation+(wheelRotation.dir)
                        wheelRotation.restart()
                        console.log("Click!!");
                    }

                    property int dir: 360
                    id:wheelRotation
                    loops: Animation.Infinite
                    duration: speedValue.value
                    onDirectionChanged: {console.log("DIRECTION CHANGED!!")}
                    onDurationChanged: {
                        wheelRotation.from = wheel.rotation
                        wheelRotation.to = wheel.rotation+(wheelRotation.dir)
                        wheelRotation.restart()
                        console.log("SPEED CHANGED!!")
                        console.log(wheelRotation.from)
                        console.log(wheelRotation.to)
                    }
                }



        MouseArea{
            anchors.fill: parent
            onClicked: { wheelRotation.changeDir() }
        }


    }
    Slider{
        width: parent.width
        id:speedValue
        value: 5000
        minimumValue: 200
        maximumValue: 10000
    }




}
