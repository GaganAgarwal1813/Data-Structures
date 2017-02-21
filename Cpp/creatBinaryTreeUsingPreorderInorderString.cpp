/*
Given a string create binary tree.
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

int SearchIndex(int *inorderSeq,int start,int stop,int data)
{
	int i = start;
	for(i = start ; i<=stop; i++)
	{
		if(inorderSeq[i] == data)
			return i;
	}
	return NULL;
}

BinaryTreeNode* createTree(int *inorderSeq,int *preorderSeq,int inorderStart,int inorderEnd)
{
	static int preorderIndex = 0;

	if(inorderStart > inorderEnd)
		return NULL;

	BinaryTreeNode* newnode = new BinaryTreeNode;
	newnode->data = preorderSeq[preorderIndex];
	preorderIndex++;
	
	if(inorderStart == inorderEnd)
		return newnode;

	int inorderIndex = SearchIndex(inorderSeq,inorderStart,inorderEnd,newnode->data);

	newnode->left = createTree(inorderSeq,preorderSeq,inorderStart,inorderIndex-1);
	newnode->right = createTree(inorderSeq,preorderSeq,inorderIndex+1,inorderEnd);

	return newnode;	
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
	int inorderSeq[]= {10,30,40,50,60,70,90};
	int preorderSeq[] = {50,30,10,40,70,60,90};

	BinaryTreeNode *root;

	root = createTree(inorderSeq,preorderSeq,0,6);

	inorderTraverse(root);



	return 0;
}