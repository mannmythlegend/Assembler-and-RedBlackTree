#ifndef PARSER_HPP
#define PARSER_HPP

#include <bitset> 
#include <cstdint>   
#include <map>       
#include <stdexcept>  
#include <string>     

#include "SymbolTable.hpp"
using namespace std;

extern SymbolTable MyST; 

class Parser{
	private:
		map<string, string> compDict;
		map<string, string> destDict;
		map<string, string> jumpDict;
		string prefixA = "0";
		string prefixC = "111";
		
		void compEntry(string key, string val);
		void destEntry(string key, string val);
		void jumpEntry(string key, string val);
		string compLookup(string instComp);
		string destLookup(string instDest);
		string jumpLookup(string instJump);
		string parseAInst(string inst);
		string parseCInst(string inst);
	
	public:
		Parser();
		~Parser();
		string parseInst(string inst);
};

#endif