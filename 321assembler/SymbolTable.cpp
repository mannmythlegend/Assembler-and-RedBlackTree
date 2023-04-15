#include "SymbolTable.hpp"


using namespace std;

SymbolTable::SymbolTable(){
	table.clear();
	
	table.insert(pair<string, uint16_t>("SP", 0));
	table.insert(pair<string, uint16_t>("LCL", 1));
	table.insert(pair<string, uint16_t>("ARG", 2));
	table.insert(pair<string, uint16_t>("THIS", 3));
	table.insert(pair<string, uint16_t>("THAT", 4));
	
	table.insert(pair<string, uint16_t>("R0", 0));
	table.insert(pair<string, uint16_t>("R1", 1));
	table.insert(pair<string, uint16_t>("R2", 2));
	table.insert(pair<string, uint16_t>("R3", 3));
	table.insert(pair<string, uint16_t>("R4", 4));
	table.insert(pair<string, uint16_t>("R5", 5));
	table.insert(pair<string, uint16_t>("R6", 6));
	table.insert(pair<string, uint16_t>("R7", 7));
	table.insert(pair<string, uint16_t>("R8", 8));
	table.insert(pair<string, uint16_t>("R9", 9));
	table.insert(pair<string, uint16_t>("R10", 10));
	table.insert(pair<string, uint16_t>("R11", 11));
	table.insert(pair<string, uint16_t>("R12", 12));
	table.insert(pair<string, uint16_t>("R13", 13));
	table.insert(pair<string, uint16_t>("R14", 14));
	table.insert(pair<string, uint16_t>("R15", 15));
	
	table.insert(pair<string, uint16_t>("SCREEN", 16384));
	table.insert(pair<string, uint16_t>("KBD", 24576));
	
	variableCounter = 16;
}

SymbolTable::~SymbolTable(){
	table.clear();
}

int SymbolTable::incLabelCounter(){
	return ++labelCounter;
}

void SymbolTable::addLabel(string Label){
	if(table.find(Label) != table.end()){
		throw runtime_error("addLabel(): redefined label");
	}
	else{
		table.insert(pair<string, uint16_t>(Label, labelCounter));
	}
}

void SymbolTable::addVariable(string Var){
	if(table.find(Var) != table.end()){
		table.insert(pair<string, uint16_t>(Var, variableCounter));
		variableCounter++;
	}
}

uint16_t SymbolTable::lookupSymbol(string Var){
	addVariable(Var);
	return table.find(Var)->second;
}