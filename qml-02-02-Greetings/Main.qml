import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("qml_02_02_Greetings")
    color: "lightgrey"

    // self-made button
    Rectangle {
        id: btnExit
        width: 100; height: width
        signal clicked()
        color: "grey"
        anchors.centerIn: parent
        Text {
            id: quit
            text: qsTr("Quit")
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 18
        }
    }
    MouseArea {
        onClicked: Qt.exit(0)
        anchors.fill: btnExit
    }
}
