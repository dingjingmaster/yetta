TEMPLATE = app
TARGET   = yettad

QT      -= gui
CONFIG  += c++11 console
CONFIG  -= app_bundle

INCLUDEPATH += \
    $$PWD/../library/

#LIBS    += -lyetta

include($$PWD/../library/library.pri)

SOURCES += \
    yetta-daemon.cpp        \
    yettad.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    yetta-daemon.h
