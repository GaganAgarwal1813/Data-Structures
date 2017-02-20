/*
Implementation of Red Black tree. 
*/

#include <iostream>

using namespace std; 


enum Color {Red,Black};

struct node
{
	int data; 
	bool color;
	node *left,*right,*parent;

	node(int data)
	{
		this->data = data;
		this->left = this->right = this->parent = NULL;
	}
};


class redBlackTree
{
	private :
		node *root;
	protected:
		void rotateLeft(node *&,node *&);
		void rotateRight(node *&,node *&);
		void fixViolation(node *&,node *&);
	public:
		redBlackTree(){root = NULL;}
		void insert(int data);
		void inorderTraversal();
};


node* BSTinsertNode(node* root,node* newNode)
{
	if (root==NULL)
		return newNode;
	if (newNode->data < root->data)
	{
		root->left = BSTinsertNode(root->left,newNode);
		root->left->parent = root;
	}

	if (newNode->data > root->data)
	{
		root->right = BSTinsertNode(root->right,newNode);
		root->right->parent = root;
	}

	return root;
}


void redBlackTree :: rotateLeft(node* &root,node* &newNode)
{
	node* rightPtr = newNode->right;
	newNode->right = rightPtr->left;
	if(newNode->right != NULL)
		newNode->right->parent = newNode;
	rightPtr->parent = newNode->parent;
 
    if (newNode->parent == NULL)
        root = rightPtr;
 
    else if (newNode == newNode->parent->left)
        newNode->parent->left = rightPtr;
 
    else
        newNode->parent->right = rightPtr;
 
    rightPtr->left = newNode;
    newNode->parent = rightPtr;
}

void redBlackTree :: rotateRight(node* &root,node* &newNode)
{
	node* leftPtr = newNode->left;
	newNode->left = leftPtr->right;

	if(newNode->left!=NULL)
		newNode->left->parent = newNode;
	leftPtr->parent = newNode->parent;
	if(newNode->parent== NULL)
		root = leftPtr;
	else if(newNode == newNode->parent->left)
		newNode->parent->left = leftPtr;
	else
		newNode->parent->right = leftPtr;

	leftPtr->right = newNode;
	newNode->parent = leftPtr;

}


void redBlackTree :: fixViolation(node *&root,node *&newNode)
{
	node* parentPtr = NULL;
	node* grandParentptr = NULL;

	while((newNode!=root) && (newNode->color!=Black) && (newNode->parent->color == Red))
	{
		parentPtr = newNode->parent;
		grandParentptr = newNode->parent->parent;

		if(parentPtr == grandParentptr->left)
		{
			node* unclePtr = grandParentptr->right;
			if(unclePtr != NULL && unclePtr->color == Red)
			{
				grandParentptr->color = Red;
				parentPtr->color = Black;
				unclePtr->color = Black;
				newNode = grandParentptr;
			}
			else
			{
				if(newNode == parentPtr->right)
				{
					rotateLeft(root,parentPtr);
					newNode = parentPtr;
					parentPtr = newNode->parent;
				}

				rotateRight(root,grandParentptr);
				swap(parentPtr->color,grandParentptr->color);
				newNode = parentPtr;
			}
		}

		else
		{
			node* unclePtr = grandParentptr->left;

			if( (unclePtr != NULL) && (unclePtr->color == Red))
			{
				grandParentptr->color = Red;
				parentPtr->color = Black;
				unclePtr->color = Black;
				newNode = grandParentptr;
			}

			else
			{
				if(newNode == parentPtr->left)
				{
					rotateRight(root,parentPtr);
					newNode = parentPtr;
					parentPtr = newNode->parent;
				}

				rotateLeft(root,grandParentptr);
				swap(parentPtr->color,grandParentptr->color);
				newNode = parentPtr;
			}	
		}
	}
	root->color = Black;
}


void redBlackTree :: insert(int data)
{
	node* newNode = new node(data);
	root = BSTinsertNode(root,newNode);

	fixViolation(root,newNode);
} 



void inorderTraversalHelper(node *root)
{
	if(root == NULL)
		return;

	inorderTraversalHelper(root->left);
	cout << root->data << " ";
	inorderTraversalHelper(root->right);
}
void redBlackTree :: inorderTraversal()
{
	inorderTraversalHelper(root);
}





int main()
{
	redBlackTree tree;
 
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    tree.inorderTraversal();


	return 0;

}