TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES += QGen_Tutorial.asn \
             dpv_rtems_gr740.dv.xml
DISTFILES += QGen_Tutorial.acn
DISTFILES += QGen_Tutorial.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters

INCLUDEPATH += simulated_data

#include(handleAsn1AcnBuild.pri)
include(work/taste.pro)
message($$DISTFILES)
