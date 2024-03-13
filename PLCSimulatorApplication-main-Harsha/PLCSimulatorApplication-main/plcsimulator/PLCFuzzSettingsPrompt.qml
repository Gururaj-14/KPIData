import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.3

Dialog {
    property var model: undefined
    property var index: undefined
    property bool isBoolean: false

    onAccepted: {
        var success = true
        success = success ? model.writeData(index, minValueField.text,
                                            "fuzzMin") : false
        success = success ? model.writeData(index, maxValueField.text,
                                            "fuzzMax") : false
        success = success ? model.writeData(index, intervalField.text,
                                            "fuzzInterval") : false

        if (!success) {
            setUp()
            error.visible = true
            open()
        }
    }

    onModelChanged: {
        if (model !== undefined && index !== undefined) {
            setUp()
        }
    }

    onIndexChanged: {
        if (model !== undefined && index !== undefined) {
            setUp()
        }
    }

    function setUp() {
        var fuzzMin = model.readData(index, "fuzzMin")
        var fuzzMax = model.readData(index, "fuzzMax")
        var fuzzInterval = model.readData(index, "fuzzInterval")

        var type = model.readData(index, "type")
        var name = model.readData(index, "name")

        minValueField.text = fuzzMin
        maxValueField.text = fuzzMax
        intervalField.text = fuzzInterval

        valueName.text = "Name : " + name
        valueType.text = "Type : " + type
        error.visible = false
    }

    ColumnLayout {

        anchors.fill: parent
        Label {
            id: header
            text: "Additional Fuzz Settings"
        }
        Item {
            height: 10
            visible: !error.visible
        }
        Label {
            id: error
            text: "Invalid input"
            color: "red"
            visible: false
            height: 10
            Layout.fillWidth: true
        }

        Label {
            id: valueName
        }
        Label {
            id: valueType
        }

        Item {
            height: 10
        }

        Label {
            id: minValueLabel
            text: "Minimum value"
            visible: !isBoolean
            Layout.fillWidth: true
        }
        TextField {
            id: minValueField
            visible: !isBoolean
            Layout.fillWidth: true
        }
        Label {
            id: maxValueLabel
            text: "Maximum value"
            visible: !isBoolean
            Layout.fillWidth: true
        }
        TextField {
            id: maxValueField
            visible: !isBoolean
            Layout.fillWidth: true
        }
        Label {
            id: intervalLabel
            text: "Fuzz interval in seconds (0 = \u221E)"
            Layout.fillWidth: true
        }
        TextField {
            id: intervalField
            Layout.fillWidth: true
        }
    }
}
