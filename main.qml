import QtQuick 2.0
import QtQuick.Layouts 1.2     // for RowLayout and ColumnLayout
import QtQuick.Controls 1.4    // for the Button


Rectangle {
    id: gameView

    width: 400
    height: 400

    border.color: "black"

    gradient: Gradient {
        GradientStop {
            position: 0.00;
            color: "#6baaf1";
        }
        GradientStop {
            position: 0.64;
            color: "#ffffff";
        }
        GradientStop {
            position: 0.98;
            color: "#175800";
        }
    }

    Action {
        id: actionOne
        text: "go 1"
        onTriggered: theOne.triggered()
    }
    Action {
        id: actionTwo
        text: "go 2"
        onTriggered: theTwo.triggered()
    }

    ColumnLayout {

        anchors.fill: parent
        Text {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop | Qt.AlignLeft
            Layout.preferredHeight: width * 0.5

            id: bigText
            text: "none"
            font.bold: true
            font.pointSize: 140
            fontSizeMode: Text.Fit
            minimumPointSize: 8
        }

        Row {
            Button {
                action: actionOne
            }
            Button {
                action: actionTwo
            }
        }
    }
}
