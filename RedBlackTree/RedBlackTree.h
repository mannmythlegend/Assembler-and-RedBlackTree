/* Honor Pledge:

I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/
#include "BinarySearchTree.h"
#include "TreeNode.h"
#include <string>
#include <iostream>

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

class RedBlackTree : public BinarySearchTree {
	public:
	
		void printRedNodes(TreeNode * root);
		
		void printBlackNodes(TreeNode * root);
	
		RedBlackTree();
	
		virtual ~RedBlackTree();
	
		virtual void insert(int data);
		
		int getHeight(TreeNode*root);
		
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
		

};

#endif