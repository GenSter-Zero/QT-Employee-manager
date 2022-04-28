QT       += core gui#添加QT所需要的相关模块
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11#意为关于程序的配置信息，+=表示在现有配置上添加

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \#指定包含的源文件
    dialog_addemp.cpp \
    dialog_adduser.cpp \
    empsql.cpp \
    emptime.cpp \
    main.cpp \
    employee.cpp \
    page_login.cpp

HEADERS += \#指定包含的头文件
    dialog_addemp.h \
    dialog_adduser.h \
    employee.h \
    empsql.h \
    emptime.h \
    page_login.h

FORMS += \#指定包含的ui文件
    dialog_addemp.ui \
    dialog_adduser.ui \
    employee.ui \
    page_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \#指定包含的资源文件
    png.qrc
