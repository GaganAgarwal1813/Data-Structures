/*
Find the largest area in the histogram.
*/


#include <iostream>

using namespace std;


int findLargestRegct(int* array,int l)
{
	int height[l];
	int index[l];
	int top=-1,i;
	int area = 0;
	int maxarea = -1;
	

	for (i=0;i<=l;i++)
	{
		while((top>=0) && (i == l || height[top] > array[i]))
		{
			
			if(top>0)
			{
				area = height[top]*(i-index[top]);
				cout << area << ' ' << height[top] << " " << (i-index[top]-1) << endl; 
			}
			top--;
			
			if(area > maxarea)
				maxarea = area;
		}
		if(i < l)
		{
			++top;
			height[top]=array[i];
			index[top] = i;
			
		}

	}
	return maxarea;
}

int main ()
{
	int a[]={1,2,3,0,5,5,5};

	cout << findLargestRegct(a,7) << endl;

	return 0;
}