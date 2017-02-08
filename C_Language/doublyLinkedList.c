/*
Implimentation of doubly linked list with following functions. 
1. Insert
2. Print
3. Delete 1st
4. Revese
*/


// Header Files

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Node Definition

struct node {
	int data;
	struct node *next;
	struct node *prev;	
};

// Defining current and head of the Linked List

struct node *head = NULL;
struct node *tail = NULL;

void insert (int data) {

	// Creates new Node
	struct node *NewNode = (struct node*) malloc(sizeof(struct node*));
	// Stores data into node
	NewNode->data = data;
	//points previos as new node
	if (head == NULL)
		head = tail;
	else
		head->prev = NewNode;
	// Points to head
	NewNode->next = head;
	// Makes New Node Head
	head = NewNode;
}

// Print Data stored in Linked List

void printList () {

	struct node *current = NULL;
	current = head;
	while (current != NULL) {
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

// Delete The first node of the linked list.

void deleteFirst () {

	if (head->next == NULL) {
		printf("Linked List is Empty.\n");
	}
	else {
		head = head->next;
	}

}

// Reverse Linked List.

void reverse () {
	struct node* current = head;
	struct node* previous = NULL;
	struct node* next;

	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;

	}
	head = previous;
}

// Main Function to do various operations on Linked List.

void main() 
{
	insert(1);
	insert(24);
	insert(3);
	insert(45);
	printList();
	deleteFirst();
	reverse();
	printList();

}
