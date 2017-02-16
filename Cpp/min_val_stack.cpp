/*
design a stack which, in addition to push and pop, also has a function
min which returns the minimum element? Push, pop and min should all operate in
O(1) time.
*/

#include <iostream>
#include <climits>
#include <vector>  //vectors can be used as stack.

using namespace std;

class stack
{
	private:
		vector<int> s;
		vector<int> min;
		int min_val = 10000;
	public:
		void push(int data);
		int pop();
		int find_min();
};

void stack :: push (int data)
{
	s.push_back(data);
	if(data <= min_val)
	{
		min.push_back(data);
		min_val = data;
	}
}

int stack :: pop()
{
	
	int i = s.back();
	s.pop_back();
	if (min.back() == s.back())
	{
		min.pop_back();
		min_val = min.back();
	}
	
	return i;
}

int stack :: find_min()
{
	int ret = min_val;
	return ret;
}

int main()
{
	stack s;
	s.push(1);
	s.push(-3);
	s.push(2);
	s.push(-12);
	s.push(21);
	s.pop();
	s.pop();
	cout << s.find_min()<<endl;

	return 0;
}