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
    src/clientwidget.cpp \
    src/data.cpp \
    src/dialog.cpp \
    src/greenteach.cpp \
    src/logwidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/clientwidget.h \
    src/data.h \
    src/dialog.h \
    src/greenteach.h \
    src/logwidget.h \
    src/mainwindow.h

FORMS += \
    src/clientwidget.ui \
    src/dialog.ui \
    src/greenteach.ui \
    src/logwidget.ui \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
