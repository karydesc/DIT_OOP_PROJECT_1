cmake_minimum_required(VERSION 3.26)

project(DIT_OOP_PROJECT_1)

set(CMAKE_CXX_STANDARD 17)


# Add the source files to the executable
add_executable(DIT_OOP_PROJECT_1
        source/pomodoro.cpp
        source/mainFrame.cpp
        source/myApp.cpp
        source/database.cpp
)
find_package(SQLite3 REQUIRED)
target_link_libraries(DIT_OOP_PROJECT_1 PRIVATE SQLite::SQLite3)

# Include wxWidgets
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net gui)
include(${wxWidgets_USE_FILE})
target_link_libraries(DIT_OOP_PROJECT_1 PRIVATE ${wxWidgets_LIBRARIES})
