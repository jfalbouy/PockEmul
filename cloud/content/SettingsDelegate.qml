
import QtQuick 1.1

Item {
    id: delegate

    property string name
    property string labelString
    property string type
    property bool saveInput: true
    property alias buttonElementEnabled: buttonElement.enabled
    property alias inputText: inputElement.text
    property alias defaultText: inputElement.defaultText
    property alias echoMode: inputElement.echoMode

    signal buttonClicked

    width: delegate.ListView.view.width;
    height: (type == "input") ? inputElement.height :
            (type == "action")? buttonElement.height +5 : labelElement.height +5


    LineInput {
        id: inputElement
        objectName: name
        width: parent.width
        label: labelString
        font.pointSize: 16
        onInputAccepted: if (saveInput) cloud.saveValueFor(key,value)
        visible: (type == "input")
    }
    ComboBox {

        visible: (type=="combo")
    }

    Row {
        y:2
        spacing: 10
        Text {
            id: labelElement
            text: labelString
            color: delegate.ListView.isCurrentItem ? "white" : "black"
            font { family: "Helvetica"; pointSize: 16; bold: false }
            anchors.verticalCenter: parent.verticalCenter
            visible: ((type == "text") | (type == "action") )
        }
        TextButton {
            id: buttonElement

            text: labelString
            objectName: name
            font.pointSize: 16
            visible: (type=="action")
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                buttonClicked();
            }
        }
    }


//    Rectangle {
//        width: delegate.width; height: 1; color: "#cccccc"
//        anchors.bottom: delegate.bottom
//        visible: delegate.ListView.isCurrentItem ? false : true
//    }
//    Rectangle {
//        width: delegate.width; height: 1; color: "white"
//        visible: delegate.ListView.isCurrentItem ? false : true
//    }

}