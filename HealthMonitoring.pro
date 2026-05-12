QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloodpressuremonitordialog.cpp \
    cancelappointmentdialog.cpp \
    doctorsappointmentdialog.cpp \
    glucosemonitordialog.cpp \
    goalsdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    navigationwindow.cpp \
    oxygenmonitordialog.cpp \
    recommendedplansdialog.cpp \
    registrationdialog.cpp \
    scheduleappointmentdialog.cpp \
    secdialog.cpp \
    temperaturemonitordialog.cpp

HEADERS += \
    bloodpressuremonitordialog.h \
    cancelappointmentdialog.h \
    doctorsappointmentdialog.h \
    glucosemonitordialog.h \
    goalsdialog.h \
    mainwindow.h \
    navigationwindow.h \
    oxygenmonitordialog.h \
    recommendedplansdialog.h \
    registrationdialog.h \
    scheduleappointmentdialog.h \
    secdialog.h \
    temperaturemonitordialog.h

FORMS += \
    bloodpressuremonitordialog.ui \
    cancelappointmentdialog.ui \
    doctorsappointmentdialog.ui \
    glucosemonitordialog.ui \
    goalsdialog.ui \
    mainwindow.ui \
    navigationwindow.ui \
    oxygenmonitordialog.ui \
    recommendedplansdialog.ui \
    registrationdialog.ui \
    scheduleappointmentdialog.ui \
    secdialog.ui \
    temperaturemonitordialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
