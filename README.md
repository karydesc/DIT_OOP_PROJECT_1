# DIT-OOP-PROJECT_1 <br>

Code written by Christos Karydis.<br>
Assignment: OOP - Project 1 | 2023<br>

Compile Instructions:<br>
WARNING: The following instructions/codes have only been tested in a macOS/Linux environment <br>
The code should theortetically work on Windows as well, however compile instructions cannot be provided.<br>
Prerequisites:<br><br>
	-A C++ compiler<br>
	-wxWidgets Library installed<br>
 	-catch2 Library installed<br>
  	-sqlite3 Library installed<br>
  	-cmake - optional<br><br>
On a Unix-like terminal:<br>
	$ cd (ROOT_DIR)<br>
	$ mkdir BUILD<br>
 	$ cd BUILD<br>
  	$ cmake ..<br>
   	$ make<br><br>
if CMake is not present, navigate to the source folder after making your build dir and run the following commands:<br>
	$ cd root/source;<br>
	$ g++ myApp.cpp mainFrame.cpp pomodoro.cpp database.cpp `wx-config --libs --cxxflags` -lsqlite3 -o ../build/Pomodoro<br><br>
 	NOTE: wx-config needs to be in your PATH environment variable in order for it to return the libs and flags to the compiler<br>

  
