include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${Qt5Xml_DEFINITIONS})

set(CMAKE_CXX_FLAGS "-Wall -O2")

###################################
# OpenCL env setup
###################################

#Linux
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        SET (EXTRA_LIBS ${EXTRA_LIBS} OpenCL)
        LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/x64 ${CMAKE_SOURCE_DIR}/lib/x86)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

#Windows support
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/x64 ${CMAKE_SOURCE_DIR}/lib/x86)
        SET (EXTRA_LIBS ${EXTRA_LIBS} OpenCL.lib)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}
    ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS "-fPIC")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(plot_SOURCES
    customPlot/qcustomplot.cpp
)

set(plot_HEADERS
    customPlot/qcustomplot.h
)

set(model_SOURCES
    model/projecttreemodel.cpp
    model/projecttreeitem.cpp
)

set(model_HEADERS
    model/projecttreemodel.h
)

set(diagram_SOURCES
    diagram/diagramscene.cpp
    diagram/diagramitem.cpp
    diagram/diagramwindow.cpp
    diagram/arrow.cpp
    diagram/connector.cpp
)

set(diagram_HEADERS
    diagram/diagramscene.h
    diagram/diagramitem.h
    diagram/diagramwindow.h
    diagram/arrow.h
    diagram/connector.cpp
    diagram/containers.h
)

set(libssh_HEADERS
)

set(libssh_SOURCES
#    libssh/libssh_authentication.c
#    libssh/libssh_connect.c
#    libssh/libsshpp.cpp
#    libssh/libssh_send.c
#    libssh/libssh_scp.c
)

set(cluster_HEADERS
    cluster/addcluster.h
    cluster/clusterconnect.h
    cluster/clustercontrol.h
)

set(cluster_SOURCES
    cluster/addcluster.cpp
    cluster/clusterconnect.cpp
    cluster/clustercontrol.cpp
)

set(settings_SOURCES
    settings/generalsettings.cpp
    settings/clustersettings.cpp
    settings/editorSettings.cpp
    settings/editorSettingsVar.cpp
)

set(settings_HEADERS
    settings/generalsettings.h
    settings/clustersettings.h
    settings/projectsettings.h
    settings/editorSettings.h
    settings/editorSettingsVar.h
)

set(projMan_SOURCES
    projManagement/addtask.cpp
    projManagement/addfiles.cpp
    projManagement/datagroup.cpp
    projManagement/adddata.cpp
    projManagement/addnewfile.cpp
    projManagement/overwritefile.cpp
)

set(projMan_HEADERS
    projManagement/addtask.h
    projManagement/addfiles.h
    projManagement/datagroup.h
    projManagement/adddata.h
    projManagement/addnewfile.h
    projManagement/overwritefile.h
)

set(projBuild_HEADERS
    projBuild/projectbuild.h
    projBuild/commandline.h
)

set(projBuild_SOURCES
    projBuild/projectbuild.cpp
    projBuild/commandline.cpp

)

set(projExe_HEADERS
    projectExec/execute.h
    projectExec/sorttask.h
    projectExec/devicequery.h
    projectExec/oneprocess.h
)
set(projExe_SOURCES
    projectExec/execute.cpp
    projectExec/sorttask.cpp
    projectExec/devicequery.cpp
    projectExec/oneprocess.cpp

)
set(test_HEADERS
    projBuild/test/testCommandLine.h
    tests/testIde.h
    tests/testdiagram.h
    tests/testdiagramscene.h
    runtests.h
    )

set(test_SOURCES
    projBuild/test/testCommandLine.cpp
    tests/testide.cpp
    tests/testdiagram.cpp
    tests/testdiagramscene.cpp
    )

set(editor_HEADERS
    editor/completionmodel.h
    )

set(editor_SOURCES
    editor/completionmodel.cpp
    )

set(whc_SOURCES
    ${plot_SOURCES}
    ${model_SOURCES}
    ${diagram_SOURCES}
    ${libssh_SOURCES}
    ${cluster_SOURCES}
    ${settings_SOURCES}
    ${projMan_SOURCES}
    ${projBuild_SOURCES}
    ${projExe_SOURCES}
    ${test_SOURCES}
    ${editor_SOURCES}
    main.cpp
    ide.cpp
    newproject.cpp
    findtool.cpp
    mdisubwindow.cpp
    mdidiagram.cpp
    mditexteditor.cpp
    highlighter.cpp
    syntaxhighlighter.cpp
    staticmethods.cpp
    monitor.cpp
    stats.cpp
)


set(whc_HEADERS
    ${plot_HEADERS}
    ${model_HEADERS}
    ${diagram_HEADERS}
    ${libssh_HEADERS}
    ${cluster_HEADERS}
    ${settings_HEADERS}
    ${projMan_HEADERS}
    ${projBuild_HEADERS}
    ${projExe_HEADERS}
    ${test_HEADERS}
    ${editor_HEADERS}
    ide.h
    newproject.h
    findtool.h
    mdisubwindow.h
    mditexteditor.h
    mdidiagram.h
    highlighter.h
    syntaxhighlighter.h
    staticmethods.h
    monitor.h
    stats.h
)

set(whc_FORMS
    forms/ide.ui
    forms/addcluster.ui
    forms/clustercontrol.ui
    forms/clusterconnect.ui
    forms/credits.ui
    forms/settingsDialog.ui
    forms/projectdialog.ui
    forms/stats.ui
)

set(whc_RESOURCES
    resources/icons.qrc
    resources/mainCppTemplate.qrc
    resources/highlighter.qrc
)

qt5_wrap_cpp(whc_HEADERS_MOC ${whc_HEADERS})
qt5_wrap_ui(whc_FORMS_UIC ${whc_FORMS})
qt5_add_resources(whc_RESOURCES_RCC ${whc_RESOURCES})

add_executable(whc
        ${whc_SOURCES}
        ${whc_HEADERS_MOC}
        ${whc_FORMS_UIC}
        ${whc_RESOURCES_RCC}
)

qt5_use_modules(whc Widgets Core Test Xml PrintSupport)

target_link_libraries(whc
    ${Qt5Widgets_LIBRARIES}
    ${LIBSSH_LIBRARIES}
    ${EXTRA_LIBS}
    iwf
)
add_dependencies(whc iwf)
