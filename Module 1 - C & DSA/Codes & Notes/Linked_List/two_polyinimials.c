#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coff;
    int pow;
    struct Node *next;
};
struct Node*addpolynomials(struct Node*head1,struct Node*head2)
{
    struct Node*curr1=head1;
    struct Node*curr2=head2;
    struct Node*dummy=malloc(sizeof(struct Node));
    dummy->coff=0;
    dummy->pow=0;
    struct Node*prev=dummy;
    while(curr1!=NULL && curr2!=NULL)
    {
   
          if (curr1->pow>curr2->pow)
          {
              prev->next=curr1;
              prev=curr1;
              curr1=curr1->next;
          }
          

        else if (curr1->pow<curr2->pow)
        {
            prev->next=curr2;
            prev=curr2;
            curr2=curr2->next;
        }
        

        else
        {
             curr1->coff=curr1->coff+curr2->coff;
             prev->next=curr1;
             prev=curr1;
             curr1=curr1->next;
             curr2=curr2->next;
        }
    }
    if(curr1!=NULL)
    {
       prev->next=curr1;
    }
    if(curr2!=NULL)
    {
        prev->next=curr2;
    }
    return dummy->next;
}
struct Node *createlist(int *ptr[], int row)
{
    if (row == 0) return NULL;

    struct Node *head = malloc(sizeof(struct Node));
    head->coff = ptr[0][0];
    head->pow  = ptr[0][1];
    head->next = NULL;

    struct Node *mover = head;

    for (int i = 1; i < row; i++) {
        struct Node *temp = malloc(sizeof(struct Node));
        temp->coff = ptr[i][0];
        temp->pow  = ptr[i][1];
        temp->next = NULL;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(void)
{
    int n, col;
    printf("Enter rows and columns for 1st list (col must be 2): ");
    scanf("%d %d", &n, &col);

    int n1, col1;
    printf("Enter rows and columns for 2nd list (col must be 2): ");
    scanf("%d %d", &n1, &col1);

    int *arr[n], *brr[n1];

   
    for (int i = 0; i < n; i++) 
    {
        arr[i] = malloc(col * sizeof(int));
        printf("Enter coeff and power for row %d: ", i);
        for (int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);
    }

    for (int i = 0; i < n1; i++) 
    {
        brr[i] = malloc(col1 * sizeof(int));
        printf("Enter coeff and power for row %d: ", i);
        for (int j = 0; j < col1; j++)
            scanf("%d", &brr[i][j]);
    }

    struct Node *head1 = createlist(arr, n);
    struct Node *head2 = createlist(brr, n1);
    struct Node*head=addpolynomials(head1,head2);
    struct Node*temp=head;
     while(temp!=NULL)
     {
        printf("%d %d ",temp->coff,temp->pow);
        temp=temp->next;
     }
  
    return 0;
}
