#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T13:26:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlashcardPro
TEMPLATE = app

INCLUDEPATH += ./src
INCLUDEPATH += ./include

SOURCES +=     src/main.cpp \
               src/mainwindow.cpp \
    src/flashcard.cpp \
    src/deck.cpp \
    src/studyarea.cpp

HEADERS  +=   include/mainwindow.h \
    include/flashcard.h \
    include/deck.h \
    include/studyarea.h
