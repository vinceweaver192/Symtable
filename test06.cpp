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


TEST_CASE("(6) basic symtable test") 
{
  symtable<string, string>  table;
	
  table.enterScope("global");
	
  table.insert("x", "char");
	
  table.insert("y", "int");
	
  table.insert("z", "string");

  table.enterScope("New");
  REQUIRE(table.curScope().Name == "New");
  string symbol;
	
  table.insert("p", "string");
	                                                                                               
  REQUIRE(!table.lookup("y", symbol, symtable<string, string>::ScopeOption::CURRENT));


}
