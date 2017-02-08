/*
Stack in C++ using linkedlist
*/

#include <iostream>
using namespace std;

class stack
{
	public:
		struct node
		{
		    int data;
		    struct node *next;
		};

		struct node *head=NULL;

		void push(int data);
		int pop();
		int isstackempty();
};



void stack :: push(int data)
{
    struct node *newNode = new node;
    newNode->data = data;
    newNode->next=head;
    head = newNode;

}

int stack :: pop()
{
    int data;
    struct node* temp = head;
    if(head==NULL)
    {
        cout << "Stack is Empty.";
        return 0;
    }
    else
    {
        data = head->data;
        head = head->next;
    }
    delete temp;
    return data;
}

int stack:: isstackempty()
{
    if(head == NULL)
        return 1;
    return 0;
}


int main()
{
    int n;
    stack s;
    s.push(5);
    s.push(10);
    n = s.pop();
    cout << n << endl;
    s.push (25);
    n=s.pop();
    n = s.pop();
    n = s.pop();
   	cout << n << endl;
    if(s.isstackempty())
        cout << "stack is empty \n";

    return 1;
}