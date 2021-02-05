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


TEST_CASE("(8) basic symtable test") 
{
  // test insert function
    symtable<string, string>  table;
  
	// testing insert 
  table.enterScope("global");
  string symbol;
	
  table.insert("i", "int");
  REQUIRE(table.size() == 1);
  REQUIRE(table.numscopes() == 1);
	
  table.enterScope("x");
  table.insert("k", "char");
  table.insert("i", "double");
  table.insert("l", "char");
   REQUIRE(table.size() == 4);
   REQUIRE(table.numscopes() == 2); 
  
	// testing exit scope
	table.exitScope();
	
   REQUIRE(table.size() == 1);
   REQUIRE(table.numscopes() == 1); 
	
  table.enterScope("dab");
  table.insert("new", "string");                                                          
  
	
  REQUIRE(table.lookup("new", symbol, symtable<string, string>::ScopeOption::CURRENT)); 
	
  table.exitScope();
	
  REQUIRE(table.lookup("i", symbol, symtable<string, string>::ScopeOption::GLOBAL)); 
  REQUIRE(symbol == "int");
	
  REQUIRE(!table.lookup("new", symbol));
}
