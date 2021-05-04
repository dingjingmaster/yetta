TEMPLATE = subdirs

SUBDIRS +=\
    src                     \


OTHER_FILES +=\
    $$PWD/README.md         \
    $$PWD/LICENSE


include($$PWD/translations/translations.pri)
