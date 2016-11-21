// Header Files

/*
This program contains singly linked list and following operations. 

1. Insert Node
2. Print Linked List
3. Delete 1st Element
4. Reverse the liked list. 
5. Find the length of liked list.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Node Definition

struct node 
{
	int data;
	struct node *next;	
};

// Defining current and head of the Linked List

struct node *head = NULL;
struct node *tail = NULL;


void insert (int data) 
{

	// Creates new Node
	struct node *NewNode = (struct node*) malloc(sizeof(struct node*));
	if (head == NULL)
		tail = NewNode;
	else
		tail->next = NewNode;
	// Stores data into node
	NewNode->data = data;
	// Points to head
	NewNode->next = head;
	// Makes New Node Head
	head = NewNode;
}

// Print Data stored in Linked List

void printList () 
{

	struct node *current = NULL;
	current = head;
	if (current == NULL)
	{
		printf("List is Empty \n");
		return ;
	}
	 do {
		printf("%d ",current->data);
		current = current->next;
	}while (head != current);
	printf("\n");
}

// Delete The first node of the linked list.

void deleteFirst () 
{

	if (head->next == NULL) {
		printf("Linked List is Empty.\n");
	}
	else {
		head = head->next;
		tail->next = head;
	}

}

// Reverse Linked List.

void reverse () 
{
	struct node* current = head;
	struct node* previous = NULL;
	struct node* next;
	tail = head;

	do  {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;

	} while (current != tail);
	head = previous;
	tail->next = head;
}

// find the length

int len() 
{
	struct node* current = head;
	int l=0;
	if (current == NULL)
	{
		return 0;
	}
	while (current->next !=head)
	{
		l++;
		current = current->next;
	} 
	return ++l;
}


//deletes nth node

/*
void delnth(int no)
{
	
	struct node* current = head;
	struct node* temp;
	int i=1,l;
	l = len();
	if (l < no)
	{
		printf("List is smaller than the number.\n");
		return;
	}
	if (l == no)
	{
		deleteFirst();
		return;
	}
	while (i < no)
	{
		current = current->next;
		i++;
	}
	temp = current->next->next;
	current->next = temp;
	
} */
// Sorts the linked list

void sortList()
{

}
// Main Function to do various operations on Linked List.

void main() 
{
	insert(5);
	insert(4);
	insert(67);
	insert(2443);
	insert(15);
	printList();	
	deleteFirst();
	reverse();
	printList();
	printf("%d\n",len() );
}
