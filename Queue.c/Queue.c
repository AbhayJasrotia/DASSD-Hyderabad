#include <stdio.h>
#include <stdlib.h>
struct queue{
    int front;
    int rear;
    int *p;
};

int isfull(struct queue *ptr,int n)
{
    return ptr->rear>=n-1;
}
int isempty(struct queue *ptr)
{
    if(ptr->front==ptr->rear)
    {
     return 1;
    }
    else
    return 0;
}
int enqueue(struct queue *ptr,int n,int a)
{
    if(isfull(ptr,n))
    return 1;

    ptr->p[++ptr->rear]=a;
    return 0;
}
int dequeue(struct queue *ptr)
{
    if(isempty(ptr))
    return 1;

    for(int i=ptr->front+1;i<=ptr->rear;i++)
    {
        ptr->p[i]=ptr->p[i+1];
    }
    ptr->rear--;
    return 0;
}
int peek(struct queue *ptr)
{
    if(isempty(ptr))
    return 1;

    printf("Peek element is %d\n",ptr->p[0]);
    return 0;
}
void display(struct queue *ptr)
{
    for(int i=ptr->front+1;i<=ptr->rear;i++)
    {
      printf("%d ",ptr->p[i]);
    }
    printf("\n");
}
int main()
{
    struct queue q;
    q.front=-1;
    q.rear=-1;
    int n;
    printf("Enter the size of the queue\n");
    scanf("%d",&n);
    q.p=(int*)malloc(n*sizeof(int));
    int choice,val;
    do
    {
        printf("1-Enqueue\n2-Deque\n3-Peek\n4-Display\nExit\n");
        printf("Enter Choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            int a;
            printf("Enter the number to be pushed into queue\n");
            scanf("%d",&a);
            if(enqueue(&q,n,a))
            printf("Queue is Full\n");
            else
            printf("%d is Pushed Into Queue\n",a);
            break;
        }
        case 2:
        {
        int b;
        printf("Enter the number to be dequed\n");
        scanf("%d",&b);
        if(dequeue(&q))
        printf("Queue is empty\n");
        else
        printf("%d is dequeued\n",b);
        break;
        }
        case 3:
        if(peek(&q))
        printf("Queue is Empty\n");
        break;
        
        case 4:
        display(&q);
        break;

        case 5:
        printf("Exiting....");

        default:
            printf("Wrong Choice");
        }
    } while (choice!=5);
    
   free(q.p);
   return 0;

}
