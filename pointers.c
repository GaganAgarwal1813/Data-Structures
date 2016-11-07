#include <stdio.h>

void main()
{
    int a=5;
    int *ptr;
    int **ptr1;
    int ***ptr2 ;
    int arr[5]={4,3,3,2,1};
    int *p;
    p=arr;
    printf("%d",*p);
    printf("%d",arr);

    ptr = &a;
    ptr1 = &ptr;
    ptr2 = &ptr1;
    printf("Value of a %d \n",a);
    printf("value of ptr %u \n",ptr);
    printf("ptr points to value %d \n",*ptr);
    printf("value of ptr1 %u \n",ptr1);
    printf("ptr1 points to value %d \n",**ptr1);
    printf("value of ptr2 %u \n",ptr2);
    printf("ptr to points to %d \n",***ptr2);

}