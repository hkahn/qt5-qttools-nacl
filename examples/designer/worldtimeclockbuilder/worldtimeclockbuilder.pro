#! [0]
CONFIG      += uitools
QT          += widgets
SOURCES     = main.cpp
RESOURCES   = worldtimeclockbuilder.qrc
#! [0]

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qttools/designer/worldtimeclockbuilder
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.ui *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qttools/designer/worldtimeclockbuilder
INSTALLS += target sources
