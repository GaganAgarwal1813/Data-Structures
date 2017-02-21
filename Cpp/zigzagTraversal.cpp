/*
Zigzag Traversal
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



void zigzagTraverse(BSTnode* root)
{
	vector<BSTnode*> currentLevel,nextLevel;
	currentLevel.push_back(root);

	int leftToRight = 1; 

	while(!(currentLevel.empty()))
	{
		BSTnode *temp;
		temp = currentLevel.back();
		currentLevel.pop_back();

		if(temp)
		{
			cout << temp->data << ' '; 
			if(leftToRight)
			{
				if (temp->left != NULL)
					nextLevel.push_back(temp->left);

				if (temp->right != NULL)
					nextLevel.push_back(temp->right);
			}
			else 
			{
				if (temp->right != NULL)
					nextLevel.push_back(temp->right);

				if (temp->left != NULL)
					nextLevel.push_back(temp->left);
			}
			if(currentLevel.empty())
			{
				leftToRight = 1 - leftToRight;
				swap(currentLevel,nextLevel);
			} 
		}
	}
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

	zigzagTraverse(b.getRoot());

	return 0;
}
