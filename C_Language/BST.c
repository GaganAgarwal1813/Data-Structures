/*
Implimentation of BST in C.
This program contains basic operations on BST.
1. Insert Node
2. Search Node
3. Delete Node
4. Find Maximum
5. Find Minimum
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

struct node* findMinimum (struct node* root)
{
	while (root->left!=NULL)
		root=root->left;
	return root;

}

int findMaximum(struct node* root)
{
	while(root->right !=NULL)
		root=root->right;
	return root->data;
}

struct node* deleteNode (struct node* root, int data)
{
	if (root == NULL)
		return root;
	else if (root->data < data)
		root->right = deleteNode (root->right,data);
	else if (root->data > data)
		root -> left = deleteNode (root->left,data);
	else 
	{
		if (root->left == NULL && root->right == NULL)
		{
		
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			struct node* temp = root;
			root=root->right;
			free(temp);
		}
		else if (root->right == NULL)
		{
			struct node* temp = root;
			root=root->left;
			free(temp);
		}
		else
		{
			struct node* temp = findMinimum(root->right); 
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);

		}
	}
	return root;
}


int findHeight(struct node* root)
{
	int leftSubTree,rightSubTree;

	leftSubTree=rightSubTree=0;

	if(root==NULL)
		return -1;

	leftSubTree = (findHeight(root->left));
	rightSubTree = (findHeight (root->right));

	return (leftSubTree > rightSubTree ? leftSubTree : rightSubTree)+1;
}

void main()
{
	Treeroot = insert(Treeroot,50);
	Treeroot = insert(Treeroot,60);
	Treeroot = insert(Treeroot,55);
	Treeroot = insert(Treeroot,25);
	Treeroot = insert(Treeroot,75);
	Treeroot = insert(Treeroot,45);
	Treeroot = insert(Treeroot,40);
	Treeroot = insert(Treeroot,35);
	Treeroot = insert(Treeroot,20);
	printf("%d \n",findMaximum(Treeroot));
	printf("%d\n",findHeight(Treeroot) );


}
