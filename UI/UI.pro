#-------------------------------------------------
#
# Project created by QtCreator 2018-07-12T13:53:59
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IslandGame
TEMPLATE = app
CONFIG += c++14


SOURCES += main.cc \
    mainwindow.cpp \
    configurationwindow.cpp \
    gameboard.cpp \
    hexagon.cpp \
    paatti.cpp \
    player.cpp \
    gamestate.cpp \
    pawnitem.cpp \
    spinnerwheel.cpp \
    spinneranimation.cpp \
    scoreboardui.cpp \
    infobox.cpp \
    monsters.cpp

HEADERS  += \
    gameboard.hh \
    player.hh \
    gamestate.hh \
    mainwindow.hh \
    configurationwindow.hh \
    hexagon.hh \
    paatti.hh \
    pawnitem.hh \
    spinnerwheel.hh \
    spinneranimation.hh \
    scoreboardui.hh \
    infobox.hh \
    monsters.hh

FORMS += \
    configurationwindow.ui\
    mainwindow.ui

INCLUDEPATH += $$PWD/../GameLogic/Engine
DEPENDPATH += $$PWD/../GameLogic/Engine

CONFIG(release, debug|release) {
   DESTDIR = release
}

CONFIG(debug, debug|release) {
   DESTDIR = debug
}

LIBS += -L$$OUT_PWD/../GameLogic/Engine
LIBS += -L$$OUT_PWD/../GameLogic/Engine/$${DESTDIR}/ -lEngine

 win32 {
    copyfiles.commands += @echo NOW COPYING ADDITIONAL FILE(S) for Windows &
    copyfiles.commands += @echo from \"$$_PRO_FILE_PWD_/../GameLogic/Assets\" to  \"$$OUT_PWD\" &
    copyfiles.commands += @call xcopy \"$$_PRO_FILE_PWD_/../GameLogic/Assets\" \"$$OUT_PWD//Assets\" /i /s /e /y
}
unix:!macx {
    copyfiles.commands += echo \"NOW COPYING ADDITIONAL FILE(S) for Linux\" &&
    copyfiles.commands += echo from $$_PRO_FILE_PWD_/../GameLogic/Assets to  $$OUT_PWD &
    copyfiles.commands += cp -r $$_PRO_FILE_PWD_/../GameLogic/Assets $$DESTDIR
}
 macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for MacOS\" &&
    copyfiles.commands += echo from $$_PRO_FILE_PWD_/../GameLogic/Assets to  $$OUT_PWD &
    copyfiles.commands += mkdir -p $$DESTDIR/IslandGame.app/Contents/MacOS &&
    copyfiles.commands += cp -r $$_PRO_FILE_PWD_/../GameLogic/Assets $$DESTDIR &&
    copyfiles.commands += cp -r $$_PRO_FILE_PWD_/../GameLogic/Assets $$DESTDIR/IslandGame.app/Contents/MacOS/
 }

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GameLogic/Engine/release/ -lEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GameLogic/Engine/debug/ -lEngine
else:unix: LIBS += -L$$OUT_PWD/../GameLogic/Engine/ -lEngine

INCLUDEPATH += $$PWD/../GameLogic/Engine
DEPENDPATH += $$PWD/../GameLogic/Engine

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GameLogic/Engine/release/libEngine.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GameLogic/Engine/debug/libEngine.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GameLogic/Engine/release/Engine.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GameLogic/Engine/debug/Engine.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../GameLogic/Engine/libEngine.a

RESOURCES += \
    kuvat.qrc

DISTFILES += \
    Instructions
