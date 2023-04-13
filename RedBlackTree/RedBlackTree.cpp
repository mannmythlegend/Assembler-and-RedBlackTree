/* Honor Pledge:

I pledge that I have neither given nor 
received any help on this assignment.
 
mmann1 and dsfield*/

#include "RedBlackTree.h"

//inherit root from BST so we can change it throughout algorith
RedBlackTree::RedBlackTree() : BinarySearchTree() {
	root_=nullptr;
}

RedBlackTree::~RedBlackTree(){
	
}

void RedBlackTree::insert(int data){
	//literally just insert from BST but calls balance color after.
	TreeNode*newNode = new TreeNode(data);
	
	root_=insertNode(root_,newNode);
	
	balanceColor(root_,newNode);

	
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode){
	/*actually newNode. Just so we can bookmark newNode and not lose
	newNode during process.*/
	TreeNode*right = newNode->getRightChild();
	
	newNode->setRightChild(right->getLeftChild());
	if(newNode->getRightChild()!=nullptr){
		//newNode's right child is set above, but to access a node,
		//there is a chance it's null so we check that first.
		newNode->getRightChild()->setParent(newNode);
	}
	
	//sets the actual nN parent to nN grandparent
	right->setParent(newNode->getParent());
	
	if(newNode->getParent()==nullptr){
		//if gpa null setRoot to actual nN
		std::cout << "setting the root to ";
		root = right;
		std::cout << root->getData() << std::endl;
	}
	else if(newNode==newNode->getParent()->getLeftChild()){
		//if parent == gpa left child, replace that with nN
		newNode->getParent()->setLeftChild(right);
	}
	else{
		//vice versa
		newNode->getParent()->setRightChild(right);
	}
	//taking care of guaranteed pointers. newNode will rise above parent.
	right->setLeftChild(newNode);
	newNode->setParent(right);
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode){
	//same thing as rotate left, just flip-flop directions!
	TreeNode*left = newNode->getLeftChild();
	
	newNode->setLeftChild(left->getRightChild());
	if(newNode->getLeftChild()!=nullptr){
		newNode->getLeftChild()->setParent(newNode);	
	}
	left->setParent(newNode->getParent());
	if(newNode->getParent()==nullptr){
		root=left;
	}
	else if(newNode==newNode->getParent()->getRightChild()){
		newNode->getParent()->setRightChild(left);
	}
	else{
		newNode->getParent()->setLeftChild(left);
	}
	
	left->setRightChild(newNode);
	newNode->setParent(left);
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode){
	std::cout << "Node inserted: " << newNode->getData() << std::endl;
	
	//coloring nodes
	if(newNode==root){
		newNode->setColor(1);
	}
	else{
		newNode->setColor(0);
	}
	
	
	//setting important nodes we need to keep track of in the while loop. p is for parent.
	TreeNode*grandpa = nullptr;
	TreeNode*uncle=nullptr;
	TreeNode*p=nullptr;
	
	while((root!=newNode)&&(newNode->getColor()!=1)&&(newNode->getParent()->getColor()!=1)){
		//clarifying parent and grandpa
		p = newNode->getParent();
		grandpa = newNode->getParent()->getParent();

		//if parent is grandpa's left child. Is important to know cause we need to
		//set the uncle, and also will factor into the type of rotate's
		if(p==grandpa->getLeftChild()){
			uncle = grandpa->getRightChild();
			
			//if uncle isn't null and is red (parent will already be red) then
			//you "flush" the black from the grandpa to the uncle and parent, and make the gpa red
			//if gpa is root we will set it back to black later
			if(uncle!=nullptr && uncle->getColor()==0){
				std::cout << "Uncle is red...Flushing color" << std::endl;
				uncle->setColor(1);
				p->setColor(1);
				grandpa->setColor(0);
					
				newNode=grandpa;
			}
			else{
				//uncle situation doesn't occur, get into the L_ rotates.
				//going into the rotates of when parent is gpa's left child.
				if(newNode==p->getRightChild()){
					rotateLeft(root, p);
					newNode=p;
					p=newNode->getParent();
				}
				else{
					rotateRight(root, grandpa);
					int tempC=p->getColor();
					p->setColor(grandpa->getColor());
					grandpa->setColor(tempC);
					newNode=p;
				}
				
			}
		}
		else{
			//parent node is grandpa's right child...assign uncle to gpas left
			uncle = grandpa->getLeftChild();
			//same uncle case as previous
			if(uncle!=nullptr && uncle->getColor()==0){
				std::cout << "Uncle is red...Flushing color" << std::endl;
				uncle->setColor(1);
				p->setColor(1);
				grandpa->setColor(0);
					
				newNode=grandpa;
			}
			else{
				
				//same rotates and traversing as before, just flip-flopped
				
				if(newNode==p->getLeftChild()){
					std::cout << "right-left rotate" << std::endl;
					rotateRight(root, p);
					newNode=p;
					p=newNode->getParent();
				}
				else{
				
					rotateLeft(root, grandpa);
					int tempC=p->getColor();
					p->setColor(grandpa->getColor());
					grandpa->setColor(tempC);
					newNode=p;
				}
			}
		}
	}
	//root can be changed from rotations, and the flush scenario, so always set it back to black at the end in case.
	root->setColor(1);

}

/*print Red Nodes will be the recursive strategy of inorder you showed,
but whenever we print we need an if statement to check if node is red.*/
void RedBlackTree::printRedNodes(TreeNode*root){
	if(root == nullptr){
		return;
	}
	
	printRedNodes(root->getLeftChild());
	
	if(root->getColor()==0){
		std::cout << root->getData() << " ";
	}
	
	printRedNodes(root->getRightChild());
}

/*print Black Nodes will be the recursive strategy of preorder you showed,
but whenever we print we need an if statement to check if node is black.*/
void RedBlackTree::printBlackNodes(TreeNode*root){
	if(root == nullptr){
		return;
	}
	
	if(root->getColor()==1){
		std::cout << root->getData() << " ";
	}
	
	printBlackNodes(root->getLeftChild());
	
	printBlackNodes(root->getRightChild());
	
}
/*extra credit. uses recursion, and traverses down the left and right by assigning them to variables.*/
int RedBlackTree::getHeight(TreeNode*root){
	if(root==nullptr){
		return 0;
	}
	
	int right=getHeight(root->getRightChild());
	int left=getHeight(root->getLeftChild());
	
	if(right>=left){
		return right+1;
	}
	else{
		return left+1;
	}
}