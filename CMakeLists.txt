cmake_minimum_required(VERSION 3.19)
project(t3_Mitza23)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


include_directories(Domain)

add_executable(t3_Mitza23
        Domain/Interval.cpp
        Domain/Interval.h
        Repository/Repository.cpp
        Repository/Repository.h UI/MainWindow.cpp UI/MainWindow.h main.cpp Domain/BetterBox.cpp Domain/BetterBox.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
