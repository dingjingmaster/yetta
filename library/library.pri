#TEMPLATE    = lib
#TARGET      = libyetta

QT          += core network

# link_pkgconfig
CONFIG      += no_keywords c++11 lrelease hide_symbols

include($$PWD/single-app/single-app.pri)

INCLUDEPATH += $$pwd

HEADERS     += \
    globals.h
