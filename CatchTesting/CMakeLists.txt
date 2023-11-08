cmake_minimum_required(VERSION 3.26)

project(CatchTest)
set(CMAKE_CXX_STANDARD 14)

# Add the source files to the executable
add_executable(CatchTest
        source/test.cpp
        source/database.cpp
        source/testMethods.cpp

)
find_package(SQLite3 REQUIRED)
target_link_libraries(CatchTest PRIVATE SQLite::SQLite3)


