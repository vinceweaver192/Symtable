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


TEST_CASE("(2) basic symtable test") 
{
  // test insert function
    symtable<string, string>  table;
  
	// testing insert 
  table.enterScope("global");
  
  table.insert("i", "int");
  REQUIRE(table.size() == 1);
  REQUIRE(table.numscopes() == 1);
	
  table.enterScope("x");
  table.insert("k", "char");
  table.insert("i", "double");
  table.insert("i", "char");
  
   REQUIRE(table.size() == 3);
   REQUIRE(table.numscopes() == 2); 
  
	// testing exit scope
	table.exitScope();
	
   REQUIRE(table.size() == 1);
   REQUIRE(table.numscopes() == 1); 
	
	table.exitScope();
	REQUIRE(table.size() == 0);
   REQUIRE(table.numscopes() == 0); 
}
