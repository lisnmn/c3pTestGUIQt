QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#QMAKE_CFLAGS_ISYSTEM = -I
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS_RELEASE += -O3 -Wall

# 添加dl库
LIBS += -ldl

# 添加采集算法库
unix|win32: LIBS += -L$$PWD/lib/ -llibOSEM
INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    util/PluginManager.cpp \
    util/dynamicUI.cpp \
    util/inifile.cpp \
    util/library.cpp

HEADERS += \
    MainWindow.h \
    include/libosem.h \
    util/PluginManager.h \
    util/abstract_plugin.h \
    util/dynamicUI.h \
    util/inifile.h \
    util/library.h \
    util/plugin.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
