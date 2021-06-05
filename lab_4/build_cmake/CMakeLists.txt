cmake_minimum_required(VERSION 3.19)
project(lab_4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

#прописать в терминале! export PATH=/usr/local/opt/qt@5/bin:$PATH

add_executable(${PROJECT_NAME}
        ../src/main.cpp
        ../src/mainwindow.cpp
        ../inc/mainwindow.h
        ../inc/lift.h
        ../src/lift.cpp
        ../inc/controller.h
        ../src/controller.cpp
        ../inc/doors.h
        ../src/doors.cpp
        ../inc/color.h
        ../inc/cabin.h
        ../src/cabin.cpp
        ../inc/ui_mainwindow
        ) 

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
