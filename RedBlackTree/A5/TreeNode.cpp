/* Honor Pledge:

I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/
#include "TreeNode.h"

//
// TreeNode(int data)
//
TreeNode::TreeNode(int data)
{
	// We could also use the initialization list here...
	
	data_ = data;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	parent_ = nullptr;
	Color color = BLACK ;
}

//
// TreeNode(const TreeNode & node)
//
/*TreeNode::TreeNode(const TreeNode & node)
{
	data_ = node.data_;
	leftChild_ = node.getLeftChild();
	rightChild_ = node.getRightChild();
	parent_ = node.getParent();
	color=node.getColor();
}*/

//
// ~TreeNode()
//
TreeNode::~TreeNode()
{
	// Recursive Delete
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

bool TreeNode::hasLeftChild(){
	if(leftChild_==nullptr){
		return false;
		
	}
	else{
		return true;
	}
	
}

bool TreeNode::hasRightChild(){
	if(leftChild_==nullptr){
		return false;
		
	}
	else{
		return true;
	}
	
}

Color TreeNode::getColor(){
	return color;
}

//
// int TreeNode::getData()
//
int TreeNode::getData()
{
	return data_;
}

//
// TreeNode * TreeNode::getLeftChild()
//
TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

//
// TreeNode * TreeNode::getRightChild()
//
TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}


void TreeNode::setColor(Color color1){
	color=color1;
}

//
// TreeNode * TreeNode::getParent()
//
TreeNode * TreeNode::getParent()
{
	return parent_;
}

bool TreeNode::hasParent(){
	if(getParent()==nullptr){
		return false;
	}
	else{
		return true;
	}
}

//
// void TreeNode::setLeftChild(TreeNode * child)
//
void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

//
// void TreeNode::setRightChild(TreeNode * child)
//
void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

//
// void TreeNode::setParent(TreeNode * parent)
//
void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}