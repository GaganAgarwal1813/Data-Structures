/*
Delete middle node of the linked list.
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
void del_middle_node(struct node<T>* ptr)
{
	struct node<T>* temp=ptr->next;
	ptr->data = ptr->next->data;
	ptr->next = ptr->next->next;
	free(temp);
}