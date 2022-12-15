QT       += core gui
QT += multimedia
QT += sql
QT += charts
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientwidget.cpp \
    data.cpp \
    dialog.cpp \
    greenteach.cpp \
    logwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    clientwidget.h \
    data.h \
    dialog.h \
    greenteach.h \
    logwidget.h \
    mainwindow.h

FORMS += \
    clientwidget.ui \
    dialog.ui \
    greenteach.ui \
    logwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gameresources.qrc
