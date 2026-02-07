#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ArrayList.hpp"


TEST_CASE( "testing the array list", "[ArrayList]" ) {

  ArrayList<int> list;
  
  list.insert(0,20);
  REQUIRE(list.getEntry(0) == 20);
  REQUIRE(list.getLength() == 1);
  list.setEntry(0,40);
  REQUIRE(list.getEntry(0) == 40);
  list.remove(0) ;
  list.clear();
    REQUIRE(list.isEmpty() == false);
  REQUIRE(list.getLength() == 0);

}
