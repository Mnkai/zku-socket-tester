cmake_minimum_required(VERSION 3.7)
project(TestProject)

set(CMAKE_CXX_STANDARD 11)

find_package (Qt5 ${QT_MIN_VERSION} REQUIRED CONFIG COMPONENTS Widgets Core Quick)

set(SOURCE_FILES main.cpp)

add_executable(TestProject ${SOURCE_FILES})
target_link_libraries(TestProject Qt5::Widgets)