QT += qml quick widgets sql

CONFIG += c++17


QTPLUGIN += QPSQL
QT_DEBUG_PLUGINS=1

DEFINES += QT_DEPRECATED_WARNINGS
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    river.cpp \
    riverlist.cpp \
    riverlistsql.cpp

HEADERS += \
    river.h \
    riverlist.h \
    riverlistsql.h

FORMS +=

RESOURCES += qml.qrc \
    qml.qrc

QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    DelegateForRiver.qml \
    DialogForAdd.qml \
    DialogForAnswer.qml \
    DialogForEdit.qml \
    main.qml \
    plugins/libiconv-2.dll \
    plugins/libintl-9.dll \
    plugins/libpq.dll

