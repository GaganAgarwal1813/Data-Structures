/*
Linked list in C++.
*/

#include <iostream>
using namespace std;


class LinkedList
{
	public:
		struct node 
		{
			int data;
			struct node *next;	
		};

		// Defining current and head of the Linked List

		struct node *head = NULL;

		void insert (int data) 
		{

			// Creates new Node
			struct node *NewNode = new node;
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
			while (current != NULL) 
			{
				cout << current->data << endl;
				current = current->next;
			}
		}

		// Delete The first node of the linked list.

		void deleteFirst () 
		{

			struct node* temp = head;
			if (head->next == NULL) 
			{
				cout<<"Linked List is Empty.\n";
			}
			else 
			{
				head = temp->next;
				delete temp;
			}

		}

		// Reverse Linked List.

		void reverse () 
		{
			struct node* current = head;
			struct node* previous = NULL;
			struct node* next;

			while (current != NULL) 
			{
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;

			}
			head = previous;
		}

		// find the length

		int len() 
		{
			struct node* current = head;
			int l;
			while (current !=NULL)
			{
				l++;
				current = current->next;
			}
			return l;
		}

		//deletes nth node

		void delnth(int no)
		{
			
			struct node* current = head;
			struct node* temp;
			int i=1,l;
			l = len();
			if (l < no)
			{
				cout << "List is smaller than the number.\n";
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
		}
			 
};


// Sorts the linked list

void sortList()
{

}
// Main Function to do various operations on Linked List.

int main() 
{

	LinkedList l;
	l.insert(5);
	l.insert(4);
	l.insert(67);
	l.insert(2443);
	l.deleteFirst();
	l.delnth(2);
	l.printList();
	
	return 1;
}