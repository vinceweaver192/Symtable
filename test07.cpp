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


TEST_CASE("(7) basic symtable test") 
{
  symtable<string, string>  table;
  symtable<string, string>::Scope newTable;
	
  table.enterScope("global");
	
  table.insert("new1", "char");
	
  table.insert("new2", "int");
	
  table.insert("new3", "string");

  newTable = table.curScope();
	
  REQUIRE(newTable.Name == "global");
  REQUIRE(newTable.Name != "X");
  REQUIRE(newTable.Symbols.count("new3") == 1);
  REQUIRE(newTable.Symbols.count("new2") == 1);
	                

}
