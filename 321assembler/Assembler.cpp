#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <iostream>
#include "Parser.hpp"
#include "SymbolTable.hpp"

//this isn't a rybar class :)
using namespace std;

SymbolTable MyST;
Parser MyParser;

int main (int argc, char const *argv[]){
	string fnameIn, fnameOut;
	ifstream fIn;
	ofstream fOut;
	
	queue<string> queue1, queue2;
	
	//handling parameters
	if(argc < 2){
		throw runtime_error("in int main(): specify input file .asm");
	}
	else{
		fnameIn = string(argv[1]);
		//check file is asm
		if(fnameIn.find(".asm")==string::npos){
			throw runtime_error("main(): file must be ASM");
		}
		
		fIn.open(fnameIn);
		//check if abled to be open
		if(!fIn.is_open()){
			throw runtime_error("unable to open file");
		}
		
		if (argc == 2){
			string::size_type idx = fnameIn.find_last_of('.');
			fnameOut = fnameIn.substr(0,idx) + ".hack";
		}
		else if(argc ==3){
			fnameOut = string(argv[2]);
		}
		else{
			throw runtime_error("main(): too many parameters");
		}
	}
	fOut.open(fnameOut);
	if(!fOut.is_open()){
		throw runtime_error("main(): unable to open file.");
	}
	
	cout << "output to " << fnameOut << endl;

	cout << "PRE=PASS" << endl;
	string line;
	
	while(getline(fIn, line)){
		cout << line << endl;
		//remove comments
		string::size_type idx = line.find("//");
		string lineRmComm = line.substr(0,idx);
		if(lineRmComm.size() == 0) continue;
		
		//remove spaces
		string::iterator str_iter = remove(lineRmComm.begin(), lineRmComm.end(), ' ');
		lineRmComm.erase(str_iter, lineRmComm.end());
		queue1.push(lineRmComm);
	}
	
	//First pass
	cout << "FIRST PASS" << endl;
	
	while(!queue1.empty()){
		line = queue1.front();
		queue1.pop();
		cout << line << endl;
		//check if label
		if(line.find('(') != string::npos && line.find(')') != string::npos){
			string::size_type idx_L = line.find_last_of('(');
            string::size_type idx_R = line.find_first_of(')');
            line = line.substr(idx_L + 1, idx_R - 1);
            MyST.addLabel(line);
            continue; 
		}
		else{
			MyST.incLabelCounter();
		}
		
		queue2.push(line);
	
		cout << "SECOND PASS" << endl;
		while(!queue2.empty()){
			line = queue2.front();
			queue2.pop();
			string macCode = MyParser.parseInst(line);
			cout << line << "\t->\t" << macCode << endl;
			fOut << macCode << endl;
		}

		cout << "2nd pass is COMPLETE" << endl;
		fIn.close();
		fOut.close();
		cout << "file closed" << endl;
	}
	
	return 0;
}