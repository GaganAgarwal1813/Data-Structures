/*
Implimentation of BST in C.
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *Treeroot = NULL;



struct node* insert(struct node *root,int data)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node*));;
	if (root == NULL)
	{
			root = newNode;
			newNode->data= data;
			newNode->left = NULL;
			newNode->right = NULL;
			return root;
	}
	else if (data > root->data)
		root->right = insert(root->right,data);
	else if (data < root->data)
		root->left = insert(root->left,data);
	else 
		printf("Data already Exist..\n");
}

void searchTree(struct node *root,int data)
{
	if (Treeroot == NULL)
	{
		printf("The tree is empty..\n");
		return;
	}

	if(root == NULL)
	{
		printf("No such entry found..\n");
		return;
	}

	if (data == root->data)
	{
		printf("Data found..\n");
	}
	else if (data > root->data)
		searchTree(root->right,data);
	else if (data < root->data)
		searchTree(root->left,data);
}

void deleteNode (struct node* root, int data)
{

}

void main()
{
	searchTree(Treeroot,100);
	Treeroot = insert(Treeroot,50);
	Treeroot = insert(Treeroot,12);
	Treeroot = insert(Treeroot,100);
	Treeroot = insert(Treeroot,25);
	Treeroot = insert(Treeroot,75);
	searchTree (Treeroot,12);
	searchTree (Treeroot,22);
}