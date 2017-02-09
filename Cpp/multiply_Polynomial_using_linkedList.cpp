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
		struct node *head = NULL;
		void insert(int data);
		void printList();
		int ListLen();		

};

void LinkedList :: insert (int data) 
{
	struct node *NewNode = new node;
	NewNode->data = data;
	NewNode->next = head;
	head = NewNode;
}

int LinkedList :: ListLen() 
{
	struct node* current = head;
	int l=0;
	while (current !=NULL)
	{
		l++;
		current = current->next;
	}
	return l;
}

void printList (struct node* head) 
{
	struct node *current = NULL;
	current = head;

	if (head == NULL)
		cout << "List is empty." << endl;
	while (current != NULL) 
	{
		cout << current->data << endl;
		current = current->next;
	}
}

struct node* poly_multi(struct node* list1,struct node* list2,int l1,int l2)
{
	
	LinkedList mul;
	int pointer = 0;
	struct node* p,*ll1,*ll2;
	int n = (l1+l2)-1;
	for (int i=0;i<n;i++)
		mul.insert(0);

	ll1 = list1;
	ll2 = list2;

	for (int i=l1;i>0;i--)
	{
		p=mul.head;
		ll2 = list2;
		for(int j=pointer;j>0;j--)
			p=p->next;


		for(int j=l2;j>0;j--)
		{
			int c;
			
			c = ll1->data * ll2->data;
			p->data = p->data + c;
			p=p->next;
			ll2=ll2->next;
		}

		pointer++;
		ll1=ll1->next;
	}
	return mul.head;
}


int main()
{
	LinkedList l1,l2;
	struct node* mul;
	l1.insert(2);
	l1.insert(3);
	l1.insert(0);
	l1.insert(1);

	l2.insert(4);
	l2.insert(0);
	l2.insert(2);
	
	mul = poly_multi(l1.head,l2.head,l1.ListLen(),l2.ListLen());
	printList(mul);

	return 1;
}
