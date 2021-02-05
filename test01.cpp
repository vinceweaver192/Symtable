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


TEST_CASE("(1) basic symtable test") 
{
  symtable<string, string>  table;
	symtable<string, string>::Scope  table1;
  
  table.enterScope("global");
  
  table.insert("i", "int");
  REQUIRE(table.size() == 1);
  REQUIRE(table.numscopes() == 1);
  
  table.enterScope("x");
  table.insert("k", "char");
  table.insert("i", "double");
  table.insert("i", "char");
  
	// testing curScope
	table1 = table.curScope();
	REQUIRE(table1.Symbols.count("k") == 1);
	REQUIRE(table1.Symbols.count("i") == 1);
	REQUIRE(table1.Symbols["k"] == "char");
	REQUIRE(table1.Symbols["i"] == "char");
	
   REQUIRE(table.size() == 3);
   REQUIRE(table.numscopes() == 2); 
  
	table.exitScope();
	
   REQUIRE(table.size() == 1);
   REQUIRE(table.numscopes() == 1); 
	
   table.dump(cout);
   table.dump(cout, symtable<string,string>::ScopeOption::CURRENT);
   table.dump(cout, symtable<string,string>::ScopeOption::GLOBAL);


}
