/*
Create Tree Using special string
*/

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	char data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* createTree(char *s,int *i)
{
	BinaryTreeNode* newNode = new BinaryTreeNode;
	newNode->data = s[*i];
	newNode->left = newNode->right = NULL;

	if(s == NULL)
	{
		delete (newNode);
		return NULL;
	}

	if(s[*i] == 'L')
		return newNode;
	*i = *i + 1;
	newNode->left = createTree(s,i);
	*i = *i + 1;
	newNode->right = createTree(s,i);

	return newNode;
} 

void inorderTraverse(BinaryTreeNode* root)
{
	if(root==NULL)
		return;
	
	cout<< root->data << ' ' ;
	inorderTraverse(root->left);
	
	inorderTraverse(root->right);
}

int main()
{
	BinaryTreeNode* root;

	char s[] = {'I','L','I','L','L'};
	int i = 0;

	root = createTree(s,&i);

	inorderTraverse(root);
	return 0;
}