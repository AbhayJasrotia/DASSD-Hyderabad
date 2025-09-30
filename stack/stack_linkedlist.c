#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node*next;
};
int isFull(int *top1,int n)
{
    return *top1==n-1;
}
int isempty(int *top)
{
    return *top==-1;
}
int push(struct Node**ptr,int val,int n,int *top1)
{       
        if(isFull(top1,n))
        {
            return 1;
        }

        struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=val;
        newnode->next=*ptr;
        *ptr=newnode;
        (*top1)++;

        return 0;
}
int pop(struct Node**ptr,int *top1)
{
     if(isempty(top1))
     {
        return 1;
     }
     struct Node*temp=*ptr;
     *ptr=temp->next;
     free(temp);
     (*top1)--;

     return 0;
}
void display(struct Node*top,int *top1)
{    if(isempty(top1))
     {
        printf("Stack is empty\n");
        return;
     }
     while(top!=NULL)
     {
        printf("%d ",top->data);
        top=top->next;
     }
     printf("\n");
}
int main()
{
    struct Node*top=NULL;
    int n;
    printf("Enter the length of the linked list\n");
    scanf("%d",&n);
    int top1=-1;
    int choice;
    do
    {
        printf("1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit\n");
        printf("Enter Choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
            int a;
            printf("Enter the number to be pushed into stack\n");
            scanf("%d",&a);
            if(push(&top,a,n,&top1))
            printf("Stack is Full\n");
            else
            printf("%d is Pushed into Stack\n",a);
            break;
            }
            case 2:
            if(pop(&top,&top1));
            printf("Stack is empty\n");
            break;

            case 3:
            display(top,&top1);
            break;
        }
    }while(choice!=4); 
    return 0;
}