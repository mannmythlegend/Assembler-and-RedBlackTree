#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include <cstdint>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

class SymbolTable {
	private:
		map<string, uint16_t> table;
		int variableCounter;
		int labelCounter;
	
	public:
		SymbolTable();
		~SymbolTable();
		int incLabelCounter();
		void addLabel(string Label);
		void addVariable(string Var);
		uint16_t lookupSymbol(string Var);
};


#endif