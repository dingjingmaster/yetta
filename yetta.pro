TEMPLATE = subdirs

CONFIG  += c++11 link_pkgconfig no_keywords

SUBDIRS += \
    src                     \
    daemon                  \


OTHER_FILES += \
    $$PWD/README.md         \
    $$PWD/LICENSE           \


include($$PWD/translations/translations.pri)
