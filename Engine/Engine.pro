#-------------------------------------------------
#
# Project created by QtCreator 2018-07-12T13:57:43
#
#-------------------------------------------------

QT       -= gui

TARGET = Engine
TEMPLATE = lib
CONFIG += staticlib c++14

HEADERS += \
    igameboard.hh \
    igamerunner.hh \
    igamestate.hh \
    iplayer.hh \
    cubecoordinate.hh \
    hex.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}
