cmake_minimum_required(VERSION 3.26)

project(DIT_OOP_PROJECT_1)

set(CMAKE_CXX_STANDARD 17)


add_executable(DIT_OOP_PROJECT_1
        main.cpp
        ./source/pomodoro.cpp
        ./source/pomodoro.h
)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net gui)
include(${wxWidgets_USE_FILE})
target_link_libraries(DIT_OOP_PROJECT_1 PRIVATE ${wxWidgets_LIBRARIES})