#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	int r,n;
	int i,index;
	scanf("%d %d",&n,&r);
	int arr[n],copy[n];
	
	for (i=0;i<n;i++){
		scanf("%d",&arr[i]);
		index = i - r;
		if (index < 0)
			index = index + n;
		copy[index] = arr[i];
	}

	for (i =0; i<n;i++){
		printf("%d ",copy[i]);
	}
        
    return 0;
}
