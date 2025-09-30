#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*delete_atk(struct Node*head,int k)
{
      printf("Node to be deleted at %d position\n",k);
      if(head==NULL) return head;
      if(k==1)
      {
        struct Node*temp=head;
        head=head->next;
        free(temp);
        return head;
        
      }
      int cnt=0;
      struct Node*temp=head;
      struct Node*prev=NULL;
      while(temp!=NULL)
      {
         cnt++;
         if(cnt==k)
         {
           prev->next=prev->next->next;
           break;
         }
         prev=temp;
         temp=temp->next;
      }
      free(temp);
      return head;
}
struct Node*delete_atlast(struct Node*head)
{
    if(head==NULL || head->next==NULL) return NULL;

    struct Node*temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
struct Node*delete_athead(struct Node*head)
{
    if(head==NULL) return head;

    struct Node*temp=head;
    head=head->next;

    free(temp);
    return head;
}
struct Node*insert_atk(struct Node*head,int k)
{
    int a;
    printf("Enter the data to be inserted at %d position\n",k);
    scanf("%d",&a);
    if(head==NULL)
    {
        struct Node*x=malloc(sizeof(struct Node));
         x->data=a;
         x->next=NULL;
         return x;
    }
    if(k==1) //If Linked List consist of only one node;
    {
        struct Node*temp=head;
        struct Node*x=malloc(sizeof(struct Node));
         x->data=a;
         x->next=NULL;
         temp->next=x;
         return temp;;
        
    }
    struct Node*temp=head;
    int count=0;
    while(temp!=NULL)
    {
       count++;
       if(count==k-1)
       {
          struct Node*newnode=malloc(sizeof(struct Node));
          newnode->data=a;
          newnode->next=temp->next;
          temp->next=newnode;
       }
       temp=temp->next;
       
    }
     return head;
}
struct Node*insert_atend(struct Node*head)
{
    int a;
    printf("Enter the data to inserted at last\n");
    scanf("%d",&a);
    if(head==NULL)
    {
        struct Node*x=malloc(sizeof(struct Node));
        x->data=a;
        x->next=NULL;
        return x;
    }
    struct Node*temp=head;
    while(temp->next!=NULL)
    {
       temp=temp->next;

    }
     struct Node*x=malloc(sizeof(struct Node));
     x->data=a;
     x->next=NULL;
     temp->next=x;
     return head;
}
struct Node*insert_atbeg(struct Node*head)
{
    int a;
    printf("Enter the data\n");
    scanf("%d",&a);
    struct Node*newnode=malloc(sizeof(struct Node));
    struct Node*temp=newnode;
    newnode->data=a;
    temp->next=head;

    return temp;

}
struct Node*createlist(int *arr,int n)
{
    struct Node*head=malloc(sizeof(struct Node));
    head->data=arr[0];
    struct Node*mover=head;
    for(int i=1;i<n;i++)
    {
        struct Node*temp=malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int main()
{
    int n;
    printf("Enter the size of the Linked List to be created\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    struct Node*head=createlist(arr,n);
    head=insert_atbeg(head);
    head=insert_atend(head);
    head=insert_atk(head,4);
    head=delete_athead(head);
    head=delete_atlast(head);
    head=delete_atk(head,4);
    struct Node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    free(arr);
    return 0;
}