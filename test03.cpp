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


TEST_CASE("(3) basic symtable test") 
{
  // test insert function
    symtable<string, string>  table;
  

  table.enterScope("global");
  
  table.insert("i", "int");
  REQUIRE(table.size() == 1);
  REQUIRE(table.numscopes() == 1);
	
  table.enterScope("x");
  table.insert("k", "char");
  table.insert("i", "int");
  table.insert("j", "double");
  
   REQUIRE(table.size() == 4);
   REQUIRE(table.numscopes() == 2); 

  //
  // these lookups should both succeed:
  //
  string symbol;
  
  REQUIRE(table.lookup("k", symbol));
  REQUIRE(symbol == "char");
  
  REQUIRE(table.lookup("i", symbol));
  REQUIRE(symbol == "int");
  
  REQUIRE(table.lookup("j", symbol));
  REQUIRE(symbol == "double");
  
  //
  // this lookup should return false:
  //
  REQUIRE((!table.lookup("x", symbol)));                                                                    
  REQUIRE(table.lookup("i", symbol, symtable<string, string>::ScopeOption::GLOBAL));            
}
