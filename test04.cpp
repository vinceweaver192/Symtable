//
// A symtable unit test based on Catch framework
//
// Vince Weaver
// U. of Illinois, Chicago
// CS 251, Spring 2020
// Project #03: symtable
//

#include <iostream>

#include "symtable.h"

#include "catch.hpp"

using namespace std;


TEST_CASE("(4) basic symtable test") 
{
  symtable<string, string>  table;
  string symbol;

  table.enterScope("global");
  
  table.insert("i", "int");
  REQUIRE(table.size() == 1);
  REQUIRE(table.numscopes() == 1);
  
  table.insert("k", "char");
  table.insert("i", "double");
  
	
   REQUIRE(table.size() == 2);
   REQUIRE(table.numscopes() == 1); 
   
	
   REQUIRE(table.lookup("k", symbol));
   REQUIRE(symbol == "char");

}
