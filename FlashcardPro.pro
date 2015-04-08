#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T13:26:48
#
#-------------------------------------------------

QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlashcardPro
TEMPLATE = app

INCLUDEPATH += ./src
INCLUDEPATH += ./include

SOURCES +=     src/main.cpp \
               src/mainwindow.cpp \
    src/flashcard.cpp \
    src/deck.cpp \
    src/studyarea.cpp \
    src/imagebox.cpp \
    src/decklabel.cpp \
    src/decksview.cpp \
    src/login.cpp \
    src/FlipWidget.cpp \
    src/RoundRectItem.cpp \
    src/mainmenu.cpp \
    src/deckmenu.cpp \
    src/statsview.cpp

HEADERS  +=   include/mainwindow.h \
    include/flashcard.h \
    include/studyarea.h \
    include/imagebox.h \
    include/deck.h \
    include/decklabel.h \
    include/decksview.h \
    include/login.h \
    include/FlipWidget.h \
    include/RoundRectItem.h \
    include/mainmenu.h \
    include/deckmenu.h \
    include/statsview.h

DISTFILES += \
    info.txt \
    test_set.txt \
    test_set2.txt \
    login_names.txt

RESOURCES += \
    images.qrc
