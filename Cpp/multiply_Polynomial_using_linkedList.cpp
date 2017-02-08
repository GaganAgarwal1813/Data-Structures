/*
Given two polynomials represented by two linkedlists that contains the coefficients of poynomials. Your task is to complete the method proOfPolynomials which takes four arguments:  the address of the head of the linked list1, the address of the head of the linked list2, size of linked list1 and size of linked list2. The function returns the head of a linked list formed after multiplication of given polynomials.

Input:

The first line contains an integer T, depicting total number of test cases. 
First line of each test case contains two integers M and N,highest degree of the polynomial linked list1 and linked list2.

Next two line contains M and N integers , decribes the coefficients of polynomials.

Output:

Print the coefficients of resultant poynomial.

Constraints:

1<=T<=100
1<=M,N<=100
1<=size of list1 & list2<=100

Example:

Input:

2
4 3
1 0 3 2
2 0 4
5 4
1 9 3 4 7
4 0 2 5

Output:

2 0 10 4 12 8
4 36 14 39 79 23 34 35
*/

#include <iostream>
using namespace std;


struct node 
{
	int data;
	struct node *next;	
};

class LinkedList
{
	public:
		struct node* createLinkedList();
		

		struct node *head = NULL;

};

struct node* LinkedList :: createLinkedList()
{
	struct node *NewNode = new node;
	return NewNode;
}

void insert (int data) 
{
	struct node *NewNode = new node;
	NewNode->data = data;
	NewNode->next = head;
	head = NewNode;
}

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