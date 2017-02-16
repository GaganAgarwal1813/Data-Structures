/*
Addition using Linkedlist.

You have two numbers represented by a linked list, where each node contains a sin-
gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
the list. Write a function that adds the two numbers and returns the sum as a linked
list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/

#include <iostream>

using namespace std;

template <typename T>
struct node
{
	T data;
	struct node* next;

};

template <class T>
class linkedList 
{
	private:
		struct node<T>* head;
	public:
		linkedList<T> () {
			head = NULL;
		};
		struct node<T>* getHead();
		void insertNode(T data);
};

template <class T>
struct node<T>* linkedList<T> :: getHead()
{
	return head;
}

template <class T>
void linkedList<T> :: insertNode(T data)
{
	struct node<T>* newNode = new node<T>;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}



struct node<int>* add_two_ll(struct node<int>* list1, struct node<int>* list2)
{
	linkedList<int> sum;
	int data,carry = 0;
	while (list1!=NULL || list2!= NULL)
	{

		data = 0;
		
		if(list1!=NULL)
		{
			data = data + list1->data;
			list1 = list1->next;
		}

		if(list2!=NULL)
		{	
			data = data + list2->data;
			list2 = list2->next;
		}
		sum.insertNode((data%10)+carry);
		carry = data/10;
			 
	} 
	if (carry!= 0)
		sum.insertNode(carry);

	return sum.getHead();
} 

int main()
{
	linkedList<int> l1,l2;
	struct node<int>* sumptr;
	struct node<int>* l1head;
	struct node<int>* l2head;
	l1.insertNode(5);
	l1.insertNode(5);
	l1.insertNode(1);
	l1.insertNode(3);
	l2.insertNode(6);
	l2.insertNode(2);
	l2.insertNode(9);
	l2.insertNode(5);

	l1head = l1.getHead();
	l2head = l2.getHead();
	sumptr = add_two_ll(l1head,l2head);

	while (sumptr!= NULL)
	{
		cout << sumptr->data << " ";
		sumptr = sumptr->next;
	}

	return 0;
}