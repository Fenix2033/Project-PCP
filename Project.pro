QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        action.cpp \
        bank.cpp \
        building.cpp \
        error.cpp \
        errorloger.cpp \
        filemanager.cpp \
        game.cpp \
        grid.cpp \
        main.cpp \
        player.cpp \
        quarry.cpp \
        sawmill.cpp

RESOURCES += qml.qrc \
            save.xml \
            savePlayer.xml


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    action.h \
    bank.h \
    building.h \
    error.h \
    errorloger.h \
    filemanager.h \
    game.h \
    grid.h \
    player.h \
    position.h \
    quarry.h \
    sawmill.h

DISTFILES += \
    save.xml \
    savePlayer.xml
