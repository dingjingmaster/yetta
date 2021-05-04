TEMPLATE    = app
QT          += core gui network dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

lessThan(QT_MAJOR_VERSION, 5) {
 QT += declarative
} else {
 QT += widgets quick qml
}

CONFIG += c++11

include($$PWD/qtsingleapplication/qtsingleapplication.pri)
include($$PWD/qmlapplicationviewer/qmlapplicationviewer.pri)

SOURCES += \
    $$PWD/main.cpp                                      \
    $$PWD/theme.cpp                                     \
    $$PWD/ksocket.cpp                                   \
    $$PWD/settings.cpp                                  \
    $$PWD/platform.cpp                                  \
    $$PWD/guibehind.cpp                                 \
    $$PWD/ktcpserver.cpp                                \
    $$PWD/chatwidget.cpp                                \
    $$PWD/duktowindow.cpp                               \
    $$PWD/duktoprotocol.cpp                             \
    $$PWD/daemonipcdbus.cpp                             \
    $$PWD/miniwebserver.cpp                             \
    $$PWD/destinationbuddy.cpp                          \
    $$PWD/ipaddressitemmodel.cpp                        \
    $$PWD/buddylistitemmodel.cpp                        \
    $$PWD/recentlistitemmodel.cpp                       \


HEADERS += \
    $$PWD/peer.h                                        \
    $$PWD/theme.h                                       \
    $$PWD/ksocket.h                                     \
    $$PWD/settings.h                                    \
    $$PWD/platform.h                                    \
    $$PWD/guibehind.h                                   \
    $$PWD/chatwidget.h                                  \
    $$PWD/duktowindow.h                                 \
    $$PWD/duktoprotocol.h                               \
    $$PWD/miniwebserver.h                               \
    $$PWD/daemonipcdbus.h                               \
    $$PWD/destinationbuddy.h                            \
    $$PWD/buddylistitemmodel.h                          \
    $$PWD/ipaddressitemmodel.h                          \
    $$PWD/recentlistitemmodel.h                         \


FORMS += \
    $$PWD/chatwidget.ui

RESOURCES += \
    $$PWD/qml.qrc

lupdate_only{
    SOURCES = qml/dukto/*.qml
}
