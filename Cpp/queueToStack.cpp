/*
Convert queue to stack. Order of data in queue and stack shoud be same.

Queue       Stack  

1 2 3 4 5   5 4 3 2 1 
F       L   L       F
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void queueToStackRecursive (queue<int>* q,stack<int>* s)
{
	if(q->empty())
		return;
	int i = q->front();
	q->pop();
	queueToStack(q,s);
	s->push(i);
}

int main()
{
	queue<int> q;
	stack<int> s;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	queueToStackRecursive(&q,&s);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	return 0;
}

