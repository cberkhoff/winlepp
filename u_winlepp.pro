TARGET = app
CONFIG += thread
TARGET = winlepp
QT += core \
    gui
HEADERS += core/refinement/selectioncriterions/subsetidcriterion.h \
    core/refinement/selectioncriterions/randomcriterion.h \
    core/refinement/refinementalgorithms/leppbisectionthread.h \
    core/util/vertexpool.h \
    core/util/pool.h \
    core/util/trianglepool.h \
    core/refinement/refinementalgorithms/leppbisectiontemplate.h \
    ui/windows/concurrencyoptionsdialog.h \
    core/refinement/refinementalgorithms/concurrentleppbisection.h \
    ui/windows/angleselectiondialog.h \
    ui/windows/mainwindow.h \
    ui/windows/refinementdialog.h \
    core/refinement/refinementalgorithms/leppbisection.h \
    core/refinement/refinementalgorithms/refinementalgorithm.h \
    core/refinement/selectioncriterions/anglecriterion.h \
    core/refinement/selectioncriterions/selectallcriterion.h \
    core/refinement/selectioncriterions/selectioncriterion.h \
    core/geom/angle.h \
    core/geom/edge.h \
    core/geom/mesh.h \
    core/geom/point2f.h \
    core/geom/triangle.h \
    core/geom/vertex.h \
    core/util/m2dmeshloader.h \
    core/util/m2dmeshsaver.h \
    core/util/meshloader.h \
    core/util/meshsaver.h \
    ui/adaptertriangleitem.h \
    ui/meshscene.h
SOURCES += core/refinement/selectioncriterions/randomcriterion.cpp \
    core/refinement/refinementalgorithms/leppbisectionthread.cpp \
    core/refinement/refinementalgorithms/leppbisectiontemplate.cpp \
    ui/windows/concurrencyoptionsdialog.cpp \
    core/refinement/refinementalgorithms/concurrentleppbisection.cpp \
    ui/windows/angleselectiondialog.cpp \
    ui/windows/mainwindow.cpp \
    ui/windows/refinementdialog.cpp \
    core/refinement/refinementalgorithms/leppbisection.cpp \
    core/refinement/refinementalgorithms/refinementalgorithm.cpp \
    core/refinement/selectioncriterions/anglecriterion.cpp \
    core/refinement/selectioncriterions/subsetidcriterion.cpp \
    core/geom/angle.cpp \
    core/geom/edge.cpp \
    core/geom/mesh.cpp \
    core/geom/point2f.cpp \
    core/geom/triangle.cpp \
    core/geom/vertex.cpp \
    core/util/m2dmeshloader.cpp \
    core/util/m2dmeshsaver.cpp \
    ui/adaptertriangleitem.cpp \
    ui/meshscene.cpp \
    main.cpp
FORMS += ui/windows/concurrencyoptionsdialog.ui \
    ui/windows/angleselectiondialog.ui \
    ui/windows/mainwindow.ui \
    ui/windows/refinementdialog.ui
RESOURCES += resources/resources.qrc
