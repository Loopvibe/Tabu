QT       += core gui widgets

TARGET = Tabu
TEMPLATE = app

VERSION = 0.2.0

UI_DIR = .build
MOC_DIR = .build
OBJECTS_DIR = .build

target.path = bin

SOURCES += \
    src/TabuAddComandWidget.cpp \
    src/TabuPrepeareGameWidget.cpp \
    src/TabuRulesDialog.cpp \
    src/main.cpp \
    src/TabuMainWindow.cpp

HEADERS += \
    src/TabuAddComandWidget.h \
    src/TabuMainWindow.h \
    src/TabuPrepeareGameWidget.h \
    src/TabuRulesDialog.h

FORMS += \
    src/TabuAddComandWidget.ui \
    src/TabuMainWindow.ui \
    src/TabuPrepeareGameWidget.ui \
    src/TabuRulesDialog.ui


INSTALLS += target
