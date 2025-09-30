#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*merge(struct Node*head1,struct Node*head2)
{
    
}
struct Node*createlist(int *arr,int n)
{
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*mover=head;
    head->data=arr[0];
    head->next=NULL;
    for(int i=0;i<n;i++)
    {
        struct Node*temp=malloc(sizeof(struct Node));
        temp->data=arr[i];
        mover->next=temp;
        mover=temp;
    }
    return head;

}
int main()
{
    int n1,n2;
    printf("Enter the size of the linked list\n");
    scanf("%d %d",&n1,&n2);

    int *ptr=(int*)malloc(n1*sizeof(int));
    int *btr=(int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int j=0;j<n2;j++)
    {
        scanf("%d",&btr[j]);
    }

    struct Node*head1=createlist(ptr,n1);
    struct Node*head2=createlist(btr,n2);
    struct Node*merge1=merge(head1,head2);

    return 0;


}