#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,Q,i;
    int c,q,no;
    int  data,lastAns;

    int seqNo;
    scanf("%d %d",&n,&Q);
    int seq[n][Q],index[n];

    for (i=0;i<n;i++)
    	index[i] = 0;
    i = 0;
    lastAns = 0;
    while (Q>0) {

    	scanf("%d %d %d",&q,&c,&data);
    	seqNo = (c ^ lastAns)%n;
    	switch (q) {
    		case 1:
    			seq[seqNo][index[seqNo]] = data;
    			index[seqNo]++;
    			break;
    		case 2:
    			no = data%(index[seqNo]);
    			lastAns = seq[seqNo][no];
                printf("%d \n",lastAns);
    			break;
		}
	Q--;
    		
	}
    return 0;
}
