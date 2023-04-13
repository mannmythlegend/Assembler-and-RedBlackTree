/* Honor Pledge:

I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/
#include "BinarySearchTree.h"

//
// BinarySearchTree()
//
BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

//
// BinarySearchTree(const BinarySearchTree & tree)
//
BinarySearchTree::BinarySearchTree(BinarySearchTree & tree)
{
	root_ = getRoot();
}

//
// ~BinarySearchTree()
//
BinarySearchTree::~BinarySearchTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

//
// TreeNode * BinarySearchTree::getRoot()
//
TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

//
// void BinarySearchTree::insert(int data)
//
void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	
	root_ = insertNode(root_, newNode);
}

void BinarySearchTree::setRoot(TreeNode*root){
	root_=root;
}

//
// TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
//
TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
	// If the BST is empty - go ahead and make the node the root.
	if (root == nullptr)
	{
		return node;
		
	}
	else
	{
		// Determine which subtree to insert the node into...
		if (node->getData() < root->getData()) 
		{ 
			// Left Subtree
			root->setLeftChild(insertNode(root->getLeftChild(), node)); 
			root->getLeftChild()->setParent(root); 
		} 
		else 
		{ 
			// Right Subtree
			root->setRightChild(insertNode(root->getRightChild(), node)); 
			root->getRightChild()->setParent(root); 
		}
		
		
		return root;
	}	
}