QT       += core gui widgets

TARGET = Tabu
TEMPLATE = app

VERSION = 0.1.0

UI_DIR = .build
MOC_DIR = .build
OBJECTS_DIR = .build

target.path = bin

SOURCES += \
    src/TabuPrepeareGameWidget.cpp \
    src/TabuRulesDialog.cpp \
    src/main.cpp \
    src/TabuMainWindow.cpp

HEADERS += \
    src/TabuMainWindow.h \
    src/TabuPrepeareGameWidget.h \
    src/TabuRulesDialog.h

FORMS += \
    src/TabuMainWindow.ui \
    src/TabuPrepeareGameWidget.ui \
    src/TabuRulesDialog.ui


INSTALLS += target
