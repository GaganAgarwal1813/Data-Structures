#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void push(int data)
{
    struct node *new = (struct node*) malloc(sizeof(struct node*));
    new->data = data;
    new->next=head;
    head = new;

}

int pop()
{
    int data;
    if(head==NULL)
    {
        printf("Stack is Empty.");
        return 0;
    }
    else
    {
        data = head->data;
        head = head->next;
    }
    return data;
}

int isstackempty()
{
    if(head == NULL)
        return 1;
    return 0;
}
void main()
{
    int n;
    push(5);
    push(10);
    n = pop();
    printf("%d ",n);
    push (25);
    n=pop();
    //n=pop();
    printf("%d ",n);
    if(isstackempty())
        printf("stack is empty \n");
}