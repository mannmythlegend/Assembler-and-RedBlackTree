/* Honor Pledge:

I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/
#ifndef TREENODE_H
#define TREENODE_H
#include <string>

enum Color { RED , BLACK };

/**
 * @class TreeNode
 *
 * A class that simulates a Node in a Binary Search Tree.
 */
class TreeNode // : public Node <-- If using your Assignment #4 code.
{
	public:
		/**
	     * Constructor
	     *
	     * @param[in]	   data		int
	    */	
		TreeNode(int data);
		
		/**
		* Copy constructor
		*
		* We need this since we have dynamically allocated
		* memory on this Class.
		*
		* @param[in]     node        Source TreeNode
		*/
		//TreeNode(const TreeNode & node);
		
		/// Destructor
		~TreeNode();
		
		
		/// Accessor Methods
		
		Color getColor();
		
		/**
	     * Returns the data stored in the tree node.
		 *
	     * @return          int
	    */ 
		int getData();
		
		bool hasLeftChild();
		
		bool hasRightChild();
		
		/**
	     * Returns a pointer to the left child of the given node.
		 *
	     * @return          TreeNode *
	    */ 		
		TreeNode * getLeftChild();
		
		/**
	     * Returns a pointer to the right child of the given node.
		 *
	     * @return          TreeNode *
	    */ 
		TreeNode * getRightChild();
		
		/**
	     * Returns a pointer to the parent of the given node.
		 *
	     * @return          TreeNode *
	    */ 
		TreeNode * getParent();
		
		/**
	     * Sets the left child of the given node.
	     *
		 * @param[in]	   TreeNode*	leftChild
	    */ 
		void setLeftChild(TreeNode * leftChild);
		
		/**
	     * Sets the right child of the given node.
	     *
		 * @param[in]	   TreeNode*	rightChild
	    */
		void setRightChild(TreeNode * rightChild);
		
		/**
	     * Sets the parent of the given node.
	     *
		 * @param[in]	   TreeNode*	parent
	    */
		void setParent(TreeNode * parent);
		
		void setColor(Color color1);
		
		bool hasParent();
	private:
		int data_; 				// Data (int) of the given node
		TreeNode * leftChild_;	// Left child node of the given node
		TreeNode * rightChild_;	// Right child node of the given node
		TreeNode * parent_;
		Color color;
		// Parent node of the given node
	protected:
		/// Protected Constructor
		TreeNode() {}
};

#endif