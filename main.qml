import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Данные о речках наших русских!")

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: btnAdd.top
        anchors.bottomMargin: 8
        border.color: "gray"
    ScrollView {
        anchors.fill: parent
        //flickableItem.interactive: true  // сохранять свойство "быть выделенным" при потере фокуса мыши

        ListView {
            id: riverList
            anchors.fill: parent
            model: riverModel // назначение модели, данные которой отображаются списком
            delegate: DelegateForRiver{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
        }
    }
   }

    Button {
        id: btnAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:btnEdit.left
        text: "Добавить речку"
        width: 100

        onClicked: windowAdd.show()
    }

    Button {
        id: btnEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: btnDel.left
        anchors.rightMargin: 8
        text: "Редактировать речку"
        width: 100

        onClicked: {
            var nameSt = riverList.currentItem.personData.nameOfRiver
            var lengthSt = riverList.currentItem.personData.lengthOfRiver
            var fallinSt = riverList.currentItem.personData.fallinForRiver
            var flowSt = riverList.currentItem.personData.flowForRiver
            var areaSt = riverList.currentItem.personData.areaOfRiver

            windowEdit.execute(nameSt, lengthSt, fallinSt, flowSt, areaSt, riverList.currentIndex)
        }
    }

    Button {
        id: btnDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить речку"
        width: 100
        enabled: riverList.currentIndex >= 0
        onClicked: del(riverList.currentIndex)
    }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit{
        id: windowEdit
    }
}
