/*
This program contains various BST travesal methods. For this code
we need BST (To apply travesal obviously!!) and queue (for level
order traversal). I am taking code from my previous implementations.

1. Level order Traversal (Breath first, requires queue to keep track of nodes)
2. Preorder Traversal (Depth first)
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_QUEUE_SIZE 100

// Queue Code....
struct QueueNode
{
	struct node* queueData[MAX_QUEUE_SIZE];
	int tail,head;
};

struct QueueNode* createQueue()
{
	struct QueueNode* queue= (struct QueueNode*) malloc(sizeof(struct QueueNode));
	queue->tail =0;
	queue->head = 0;
	return queue;
}

void enqueue(struct QueueNode* queue,struct node* data)
{
	
	queue->queueData[queue->head] = data;
	queue->head = queue->head + 1;
	if(queue->head >=MAX_QUEUE_SIZE)
		queue->head=0;

}

struct node* dequeue(struct QueueNode* queue)
{
	struct node* data;

	if(queue->tail >= queue->head)
	{
		queue->tail=queue->head=0;
	}
	data = queue->queueData[queue->tail];
	queue->tail++;
	
	
	if(queue->tail >=MAX_QUEUE_SIZE)
		queue->tail=0;

	return data;
}

int isEmptyQueue (struct QueueNode* queue)
{
	if(queue->tail >= queue->head)
		return 1;
	else
		return 0;
}

// BST code.....

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


// Level Order Traversal...

void levelOrderTraversal(struct node* root)
{
	struct node* temp = root;
	struct QueueNode* traverseQueue;
	traverseQueue = createQueue();
	enqueue(traverseQueue,temp);
	while (!isEmptyQueue(traverseQueue))
	{
		temp = dequeue(traverseQueue);

		printf("%d ",temp->data);
		
		if(temp->left != NULL)
			enqueue(traverseQueue,temp->left);
		
		if(temp->right != NULL)
			enqueue(traverseQueue,temp->right);
		}
}

// Preorder Traversal..

void preorderTraversal(struct node* root)
{
	if (root == NULL)
		return;

	printf("%d ",root->data);

	preorderTraversal(root->left);
	preorderTraversal(root->right);

}

//Testing code starts from here...

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
	levelOrderTraversal(Treeroot);
	printf("\n");
	preorderTraversal(Treeroot);

}