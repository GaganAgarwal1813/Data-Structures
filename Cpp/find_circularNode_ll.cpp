/*
find linked list is circular or not...
*/

#include <iostream>
#include <unordered_set>
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
bool find_circular(struct node<T>* head)
{
	unordered_set <struct node<T>*> set;
	if (head == NULL)
		return false;
	while(head!= NULL)
	{
		if (set.find(head)!=set.end())
		{
			cout << "circular node found at " << head << "with value " << head->data << endl ; 
			return true;
		}
		set.insert(head);
		head = head->next;

	}
	return false;
}

int main()
{
	linkedList<int> l1;
	struct node<int>* l1Head,*temp;
	l1.insertNode(11);
	l1.insertNode(11);
	l1.insertNode(12);
	l1.insertNode(54);
	l1.insertNode(14);
	temp = l1.getHead();
	l1.insertNode(11);
	l1.insertNode(11);
	l1.insertNode(54);
	l1.insertNode(11);
	l1.insertNode(11);
	l1.insertNode(11);
	l1.insertNode(11);
	l1Head = l1.getHead();
	temp->next = l1Head;
	cout << find_circular(l1Head) << endl;
	return 0;
}