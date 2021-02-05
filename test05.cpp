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


TEST_CASE("(5) basic symtable test") 
{
  symtable<string, string>  table;
  symtable<string, string>::Scope scope;
	
	try{
		scope = table.curScope();
		REQUIRE(false);
	}
	catch(...){
		REQUIRE(true);
	}
	REQUIRE_THROWS(table.exitScope());

}
