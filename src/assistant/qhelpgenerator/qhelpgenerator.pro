TEMPLATE = app
TARGET = qhelpgenerator
DESTDIR = $$QT.designer.bins
CONFIG += qt warn_on help console
CONFIG -= app_bundle
QT += network help-private

target.path=$$[QT_INSTALL_BINS]
INSTALLS += target

SOURCES += ../shared/helpgenerator.cpp \
           main.cpp

HEADERS += ../shared/helpgenerator.h
