#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LinkedList.hpp"


TEST_CASE( "TODO", "[LinkedList]" ) {

    LinkedList<int> list;
     
  list.insert(0, 20);
  REQUIRE(list.getEntry(0) == 20);
  REQUIRE(list.getLength() == 1);
  list.insert(1, 30);
  REQUIRE(list.getEntry(1) == 30);
  REQUIRE(list.getLength() == 2);
  list.setEntry(0, 40);
  REQUIRE(list.getEntry(0) == 40);
  list.remove(0);
  REQUIRE(list.getEntry(0) == 30);
  REQUIRE(list.getLength() == 1);
  list.clear();
  REQUIRE(list.isEmpty() == true);
  REQUIRE(list.getLength() == 0);

}