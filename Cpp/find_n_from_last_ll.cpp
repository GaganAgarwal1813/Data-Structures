/*
Find nth from the start in a linked list.
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

template <typename T>
struct node<T>* find_Nth_from_last(struct node<T>* head,int n)
{
	struct node<T>* rev = head;
	int i=0;
	while(head!= NULL)
	{
		if(i>=n-1)
			rev=rev->next;
		head=head->next;
		i++;
	}
	if (i==0)
		return NULL;
	return rev;
}


int main()
{
	linkedList<int> l1;
	struct node<int>* ref;
	l1.insertNode(1);
	l1.insertNode(2);
	l1.insertNode(3);
	l1.insertNode(4);
	l1.insertNode(5);
	l1.insertNode(6);
	l1.insertNode(7);
	ref = l1.getHead();
	ref = find_Nth_from_last(ref,2);

	cout << ref->data << endl;
}