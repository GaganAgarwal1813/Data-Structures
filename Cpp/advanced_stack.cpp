/*
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. There-
fore, in real life, we would likely start a new stack when the previous stack exceeds
some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
Stacks should be composed of several stacks, and should create a new stack once
the previous one excet eds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is, pop() should return the same values as it
would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific
sub-stack.
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class advanced_stack
{
	private:
		unordered_map <int,vector<int>*> stack_map;
		vector<int>* vptr;
		int stackRef =0;
		int dataRef=0;
		vector<int>* create_newStack();
	public:
		advanced_stack()
		{
			vptr = create_newStack();
		}
		void push(int data);
		int pop();
		int pop(int i);
};

vector<int>* advanced_stack :: create_newStack()
{
	vector<int> *stack = new vector<int>(10);
	cout << "new stack created" << endl;
	stackRef++;
	stack_map.insert({stackRef,stack});

	return stack;
}

void advanced_stack :: push(int data)
{
	dataRef++;
	if (dataRef > 3)
	{
		vptr = create_newStack();
		dataRef = 0;
	}
	vptr->push_back(data);
}

int advanced_stack :: pop()
{
	if(vptr->back() == NULL)
		vptr = stack_map[--stackRef];
	
	cout << stackRef << endl; 

	int ret = vptr->back();
	vptr->pop_back();
	return ret;
}

int advanced_stack :: pop (int i)
{
	return stack_map[i]->back();
} 
int main()
{
	advanced_stack s;
	s.push(1);
	s.push(1);
	s.push(5);
	s.push(2);
	s.push(2);
	s.push(2);
	s.push(2);
	//s.pop();
	cout << s.pop() << endl;
	return 0;
}