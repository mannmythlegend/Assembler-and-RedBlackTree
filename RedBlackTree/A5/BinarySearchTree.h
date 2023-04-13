/* Honor Pledge:

I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <iostream>

/**
 * @class BinarySearchTree
 *
 * A Class that simulates a Binary Search Tree.
 */
class BinarySearchTree : public TreeNode
{
	public:
		/// Constructor
		BinarySearchTree();
		
		/**
		* Copy constructor
		*
		* We need this since we have dynamically allocated
		* memory on this Class.
		*
		* @param[in]     tree        Source BinarySearchTree
		*/
		BinarySearchTree(BinarySearchTree & tree);
		
		/// Destructor
		~BinarySearchTree();
		
		/**
	     * Returns a pointer to the root node of the BST.
		 *
	     * @return          TreeNode*
	    */ 
		TreeNode * getRoot();
		
		void setRoot(TreeNode*root);
		
		/**
	     * Inserts a data element into the BST.
	     *
		 * @param[in]	   int	data
	    */ 
		void insert(int data);
		
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
	
	protected:
		TreeNode * root_;
	
	private:
		/**
	     * Helper method to insert a TreeNode into the BST.
	     *
		 * @param[in]	   TreeNode*	root	
		 * @param[in]	   TreeNode*	newNode
		 *
	     * @return          TreeNode*
	    */ 
		
		 // Pointer to the root node of the BST
};

#endif