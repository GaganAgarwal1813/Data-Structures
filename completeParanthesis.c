/*
This program used to check whether the paranthesis are 
complete or not.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *head=NULL;

void push(char data)
{
    struct node *new = (struct node*) malloc(sizeof(struct node*));
    new->data = data;
    new->next=head;
    head = new;

}

char pop()
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
    char str[] = "{{}}[()](([{}])";
    char ch;
    int i;
    for (i=0;i<strlen(str);i++)
    {
        if (str[i]=='{' || str[i]=='(' || str[i]=='[')
            push(str[i]);
        else if (str[i]=='}' || str[i]==')' || str[i]==']')
        {
            ch = pop();
            if((str[i]=='}' && ch=='{') || (str[i]==']' && ch=='[') || (str[i]==')' && ch=='('))
                continue;
            else
                break;
        }
    }
    if (isstackempty())
        printf("Expression is complete. \n");
    else
        printf("Expression is not complete. \n");
}