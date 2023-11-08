# define CATCH_CONFIG_MAIN
#include "testMethods.h"
#include "catch.hpp"
#include "database.h"

testMethods test;

TEST_CASE("pauseSession() works"){
    test.pauseSession();
    REQUIRE(test.pauseFlag==true);
}
TEST_CASE("Creating .txt works"){

    REQUIRE(test.checkFile()==true);
}
TEST_CASE("Database: Adding works"){
    database database;
    REQUIRE(database.addUser("chris","password")==true);
}
TEST_CASE("Database: Authenticating works"){
    database database;
    REQUIRE(database.authUser("chris","password")==true);
}