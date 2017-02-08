/*
Double Linked List Implimentation in C++.
*/

/*
Implimentation of doubly linked list with following functions. 
1. Insert
2. Print
3. Delete 1st
4. Revese
*/


// Header Files

#include <iostream>
using namespace std;

// Node Definition
class doublyLinkedList
{
	public:
		struct node 
		{
			int data;
			struct node *next;
			struct node *prev;	
		};
		// Defining current and head of the Linked List

		struct node *head = NULL;
		struct node *tail = NULL;

		//Declaring functions..

		void insert(int data);
		void printList();
		void deleteFirst();
		void reverse();
};


void doublyLinkedList :: insert (int data) 
{

	// Creates new Node
	struct node *NewNode = new node;
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

void doublyLinkedList :: printList () {

	struct node *current = NULL;
	current = head;
	while (current != NULL) {
		cout<<current->data<<endl;
		current = current->next;
	}
}

// Delete The first node of the linked list.

void doublyLinkedList :: deleteFirst () {

	struct node* temp = head;
	if (head->next == NULL) {
		cout << "Linked List is Empty.\n";
	}
	else {
		head = temp->next;
	}
	delete temp;
}

// Reverse Linked List.

void doublyLinkedList :: reverse () {
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

int main() 
{
	doublyLinkedList dl;

	dl.insert(1);
	dl.insert(24);
	dl.insert(3);
	dl.insert(45);
	dl.printList();
	dl.deleteFirst();
	dl.reverse();
	dl.printList();


	return 1;
}
