cmake_minimum_required(VERSION 3.5)

project(ArithmeticBaseConverter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        app-icon.qrc
)

if(APPLE)
    set_source_files_properties(assets/app-icon.icns PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
    )
    list(APPEND PROJECT_SOURCES assets/app-icon.icns)
endif()

if(WIN32)
    list(APPEND PROJECT_SOURCES app-icon.rc)
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ArithmeticBaseConverter
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        basesmanager.h basesmanager.cpp
        basesitemmodel.h basesitemmodel.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ArithmeticBaseConverter APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ArithmeticBaseConverter SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ArithmeticBaseConverter
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ArithmeticBaseConverter PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(APPLE)
    set_target_properties(ArithmeticBaseConverter PROPERTIES
        MACOSX_BUNDLE_ICON_FILE app-icon.icns
    )
endif()

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ArithmeticBaseConverter)
endif()
set_target_properties(ArithmeticBaseConverter PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ArithmeticBaseConverter
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ArithmeticBaseConverter)
endif()
