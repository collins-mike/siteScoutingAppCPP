#-------------------------------------------------
#
# Project created by QtCreator 2017-12-29T14:42:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SiteScoutingApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    testconstainer.cpp \
    specan.cpp \
    qcustomplot.cpp \
    advsettings.cpp

HEADERS += \
        mainwindow.h \
    bb_api.h \
    testconstainer.h \
    specan.h \
    qcustomplot.h \
    advsettings.h

FORMS += \
        mainwindow.ui \
    advsettings.ui
DISTFILES += \
    bb_api.lib \
    bb_api.dll \
    ftd2xx.dll


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -lbb_api
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -lbb_api
else:unix: LIBS += -L$$PWD/./ -lbb_api

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''
