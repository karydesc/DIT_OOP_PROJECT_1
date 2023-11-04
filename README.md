# DIT-OOP-PROJECT_1

Code written by Christos Karydis.
Assignment: OOP - Project 1 | 2023

Compile Instructions:
WARNING: The following instructions/codes have only been tested in a macOS/Linux environment 
The code should theortetically work on Windows as well, however compile instructions cannot be provided.
Prerequisites:
	-A C++ compiler
	-wxWidgets Library installed
 	-catch2 Library installed
  	-sqlite3 Library installed
  	-cmake - optional
On a Unix terminal:
	$ cd (ROOT_DIR)
	$ mkdir BUILD
 	$ cd BUILD
  	$ cmake ..
   	$ make
if CMake is not present, navigate to the source folder after making your build dir and run the following commands
	$ cd root/source;
	$ g++ myApp.cpp mainFrame.cpp pomodoro.cpp database.cpp `wx-config --libs --cxxflags` -lsqlite3 -o ../build/Pomodoro
 	NOTE: wx-config needs to be in your PATH environment variable in order for it to return the libs and flags to the compiler

  
