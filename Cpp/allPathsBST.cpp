/*
Find all possible path in a BST.
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

vector<int> v;

void allPathsBST(BSTnode *root)
{

	if(root->left == NULL && root->right == NULL)
	{
		v.push_back(root->data);
		for (auto i = v.begin(); i != v.end(); ++i)
    		std::cout << *i << ' ';
    	cout << endl;
    	v.pop_back();
		return;
	}
	v.push_back(root->data);
	allPathsBST(root->left);
	allPathsBST (root->right);
	v.pop_back();
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

	allPathsBST(b.getRoot());


	return 0;
}