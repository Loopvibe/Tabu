QT       += core gui widgets

TARGET = Tabu
TEMPLATE = app

VERSION = 0.4.0

UI_DIR = .build
MOC_DIR = .build
OBJECTS_DIR = .build

DESTDIR = bin

SOURCES += \
    src/TabuAddTeamWidget.cpp \
    src/TabuGameWidget.cpp \
    src/TabuPrepeareGameWidget.cpp \
    src/TabuRulesDialog.cpp \
    src/TabuWord.cpp \
    src/main.cpp \
    src/TabuMainWindow.cpp

HEADERS += \
    src/TabuAddTeamWidget.h \
    src/TabuGameWidget.h \
    src/TabuMainWindow.h \
    src/TabuPrepeareGameWidget.h \
    src/TabuRulesDialog.h \
    src/TabuWord.h

FORMS += \
    src/TabuAddTeamWidget.ui \
    src/TabuGameWidget.ui \
    src/TabuMainWindow.ui \
    src/TabuPrepeareGameWidget.ui \
    src/TabuRulesDialog.ui


INSTALLS += target
