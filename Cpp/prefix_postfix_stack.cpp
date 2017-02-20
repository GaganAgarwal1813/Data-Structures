/*
Prefix Postfix conversion usng stack.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> stack;

int get_Answer(int x,int y,char op)
{
	if(op == '+')
		return (x+y);
	if(op == '*')
		return (x*y);
	if(op == '/')
		return (x/y);
	if(op == '-')
		return (x-y);
}

int prefix_conversion(string &s)
{
	int i;
	int ans = 0;
	for (i=s.length()-1;i>=0;i--)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i]== '/')
		{
			
			int a,b;
			a = stack.back();
			stack.pop_back();
			b = stack.back();
			stack.pop_back();
			 
			ans = get_Answer(a,b,s[i]);
			stack.push_back(ans);
		}
		else 
		{
			int j;
			j = s[i] - 48;
			cout <<j<< endl;
			stack.push_back(j);
		}
	}
	return ans;
}


int postfix_conversion(string &s)
{
	int i;
	int ans = 0;
	for (i=0;i<s.length();i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i]== '/')
		{
			
			int a,b;
			a = stack.back();
			stack.pop_back();
			b = stack.back();
			stack.pop_back();
			 
			ans = get_Answer(a,b,s[i]);
			stack.push_back(ans);
		}
		else 
		{
			int j;
			j = s[i] - 48;
			cout <<j<< endl;
			stack.push_back(j);
		}
	}
	return ans;
}


int main()
{
	string s = "457++";
	cout << postfix_conversion(s)  << endl;

	return 0;
}