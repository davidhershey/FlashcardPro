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
    src/flashcard.cpp \
    src/imagebox.cpp \
    src/decklabel.cpp \
    src/decksview.cpp \
    src/login.cpp \
    src/FlipWidget.cpp \
    src/RoundRectItem.cpp

HEADERS  +=   include/mainwindow.h \
    include/flashcard.h \
    include/studyarea.h \
    include/flashcard.h \
    include/imagebox.h \
    include/deck.h \
    src/decklabel.h \
    include/decklabel.h \
    decksview.h \
    include/decksview.h \
    login.h \
    include/login.h \
    include/FlipWidget.h \
    include/RoundRectItem.h

DISTFILES += \
    info.txt \
    test_set.txt \
    test_set2.txt
