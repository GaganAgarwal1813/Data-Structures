#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,q,i,j,count;
    scanf("%d",&n);
    char str[n][20];

    for (i=0;i<n;i++){
    	fgets(str[i],20,stdin);
    }

    scanf("%d",&q);

    char que[q][20]; 

    for (i=0;i<n;i++){
    	fgets(que[i],20,stdin);
    }

    for (i=0;i<q;i++){
    	count = 0;
    	for (j=0;j<n;j++){
    		if(strcmp(str[j],que[q]))
    			count++;

    	}
    	printf("%d \n",count);
    }


    return 0;
}
