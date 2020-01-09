#-------------------------------------------------
#
# Project created by QtCreator 2020-01-07T13:52:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpencvTest
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        threadbaiduapi.cpp \
        threadfacecapture.cpp

HEADERS += \
        mainwindow.h \
        threadbaiduapi.h \
        threadfacecapture.h

FORMS += \
        mainwindow.ui

# opencv 依赖库和头文件
INCLUDEPATH += D:/opencv/build/include
LIBS += D:\opencv\build\x64\vc15\lib\opencv_world346d.lib
# jsoncpp 依赖库和有文件
INCLUDEPATH += C:\Users\26235\Documents\GitDocu\vcpkg\packages\jsoncpp_x86-windows\include
LIBS += C:\Users\26235\Documents\GitDocu\vcpkg\packages\jsoncpp_x86-windows\lib\jsoncpp.lib
# curl 依赖库和有文件
INCLUDEPATH += C:\Users\26235\Documents\GitDocu\vcpkg\packages\curl_x86-windows\include
LIBS += C:\Users\26235\Documents\GitDocu\vcpkg\packages\curl_x86-windows\lib\libcurl.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
