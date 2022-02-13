cmake_minimum_required(VERSION 3.1.0)

project(QDetachTabWidget VERSION 1.0.1 LANGUAGES CXX)

set(PROJECT_NAME QDetachTabWidget)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH ${QTDIR})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(HEADER_FILES
    QDetachTabWidget.h
    )

set(SOURCE_FILES
    main.cpp
    QDetachTabWidget.cpp
    )

# Set non-Debug build as GUI application.
# Debug build remains consle application.
if(NOT CMAKE_BUILD_TYPE MATCHES Debug) #Release, RelWithDebInfo and MinSizeRel
    if(WIN32) # Check if we are on Windows
        set(SYSTEM_TYPE WIN32)
    elseif(APPLE) # MacOS X
        set(SYSTEM_TYPE MACOSX_BUNDLE)
    else() # UNIX
        set(SYSTEM_TYPE EXCLUDE_FROM_ALL)
    endif()
    message("System type is" ${SYSTEM_TYPE})
endif()

add_compile_definitions(QT_DEPRECATED_WARNINGS)

add_executable(${PROJECT_NAME} ${SYSTEM_TYPE} ${SOURCE_FILES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Gui Qt5::Core)

