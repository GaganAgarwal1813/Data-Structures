/*
Mirror of a Tree.
*/

#include <iostream>
#include <vector>

using namespace std;


struct BSTnode
{
	int data;
	BSTnode* left;
	BSTnode* right;
	BSTnode(int data)
	{
		this->data = data;
		this->left = this->right = NULL;
	}
};

class BST
{
private:
	BSTnode* root;
protected:
	BSTnode* insertNodeHelper (BSTnode *root,int data);
public:
	BST(){ root = NULL; }
	void insertNode(int data);
	BSTnode* getRoot()
	{
		BSTnode* temp = root;
		return temp;
	}
};


BSTnode* BST :: insertNodeHelper(BSTnode* root,int data)
{
	if(root == NULL)
	{
		BSTnode* newNode = new BSTnode(data);
		return newNode;
	}
	if(data > root->data)
		root->right = insertNodeHelper(root->right,data);
	if(data < root->data)
		root->left = insertNodeHelper(root->left,data);

	return root;
}

void BST :: insertNode (int data)
{
	root = insertNodeHelper(root,data);
}

void mirrorTree(BSTnode* root)
{
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL)
		return;
	mirrorTree(root->left);
	mirrorTree(root->right);
	if(root->left != NULL || root->right != NULL)
	{
		BSTnode* temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void inorderTraverse(BSTnode* root)
{
	if(root==NULL)
		return;
	inorderTraverse(root->left);
	cout<< root->data << ' ' ;
	inorderTraverse(root->right);
}
int main()
{
	BST b;

	b.insertNode(10);
	b.insertNode(8);
	b.insertNode(12);
	b.insertNode(9);
	b.insertNode(7);
	b.insertNode(11);
	b.insertNode(13);

	mirrorTree(b.getRoot());
	inorderTraverse(b.getRoot());

	return 0;
}