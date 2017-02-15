/*
Remove duplicates from the linked list. 
1. using extra space.
2. without using extra space.
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
void remove_dups_space(struct node<T>* head)
{
	if (head == NULL)
		return;
	unordered_set<T> list;
	struct node<T>* temp = head;
	struct node<T>* prev = temp;
	while(temp->next != NULL)
	{
		
		
		if (list.find(temp->data)!=list.end())
		{

			prev->next = temp->next;
			free(temp);
			temp = prev->next;
			continue;
		}
		 
		list.insert(temp->data);
		prev = temp;
		temp = temp->next;

	}
}


template <typename T>
void remove_dups_NoSpace(struct node<T>* head)
{
	if (head == NULL)
		return;
	struct node<T>* tempi=head;
	struct node<T>* tempj;
	struct node<T>* prev;

	while(tempi->next != NULL)
	{
		tempj = tempi->next;
		prev = tempi;
		while(tempj->next != NULL)
		{
			
			if (tempi->data == tempj->data)
			{
				prev->next = tempj->next;
				free(tempj);
				tempj = prev->next;
				continue;
			}
			prev = prev->next;
			tempj = tempj->next;
		}
		tempi= tempi->next;
	}
}


int main()
{
		linkedList<int> l1;
		struct node<int>* l1Head;
		l1.insertNode(11);
		l1.insertNode(11);
		l1.insertNode(12);
		l1.insertNode(54);
		l1.insertNode(14);
		l1.insertNode(11);
		l1.insertNode(11);
		l1.insertNode(54);
		l1.insertNode(11);
		l1.insertNode(11);
		l1.insertNode(11);
		l1.insertNode(11);
		l1Head = l1.getHead();
		//remove_dups_space(l1Head);
		remove_dups_NoSpace(l1Head);
		while(l1Head->next!=NULL)
		{
			cout << l1Head->data << endl;
			l1Head = l1Head->next;
		}


	return 0;
}