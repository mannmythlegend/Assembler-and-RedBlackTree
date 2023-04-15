/* Honor Pledge:
I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/
#include <iostream>
#include <string>
#include <fstream>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
 
int main(){
	//Phase 1, 2, and 3
	//opening txt file
	std::ifstream inputfile;
	inputfile.open("data-1.txt");
	int temp=0;
	//getting numbers from the txt file by initializing RedBlackTree and making a while loop to read and insert
	std::cout << "Getting numbers..." << std::endl;
	RedBlackTree rbt;
	while(!inputfile.eof()){
		inputfile >> temp;
		rbt.insert(temp);
	}
	
	//print root and the roots color
	
	if(rbt.getRoot()==nullptr){
		std::cout << "root is null" << std::endl;
	}
	else{
		std::cout << "Root: " << rbt.getRoot()->getData() << std::endl;
		if(rbt.getRoot()->getColor()==1){
			std::cout << "Color: BLACK" << std::endl;
		}
		else{
			std::cout << "Color: RED" << std::endl;
		}
		std::cout << "Red Nodes: ";
		rbt.printRedNodes(rbt.getRoot());
		std::cout << "" << std::endl;
		
		std::cout << "Black Nodes: ";
		rbt.printBlackNodes(rbt.getRoot());
		std::cout << "" << std::endl;
		std::cout << "Height: " << rbt.getHeight(rbt.getRoot()) << std::endl;
	}
	
	//closing txt
	inputfile.close();
	
	return 0;
}