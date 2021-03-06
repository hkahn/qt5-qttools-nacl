TEMPLATE = app

CONFIG += help
QT     += widgets
SOURCES += main.cpp \
           wateringconfigdialog.cpp \
           helpbrowser.cpp

HEADERS += wateringconfigdialog.h \
           helpbrowser.h

FORMS   += wateringconfigdialog.ui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qttools/help/contextsensitivehelp
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro *.png *.doc doc
sources.path = $$[QT_INSTALL_EXAMPLES]/qttools/help/contextsensitivehelp
INSTALLS += target sources
