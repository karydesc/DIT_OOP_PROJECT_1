//
// Created by Chris on 8/11/23.
//

#include "testMethods.h"
#include <fstream>
using namespace std;
void testMethods::pauseSession() {
    pauseFlag=!pauseFlag;
}
bool testMethods::checkFile() {
    ofstream myFile("./test.txt");
    if (myFile.is_open()){
        myFile.close();
        return true;
    }else{
        myFile.close();
        return false;
    }
}
