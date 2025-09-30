#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct library_management
{
    int book_id;
    char *title;
    char author[100];
    int price;
    int yop;
};
void average_price(struct library_management*ptr,int n)
{
    int avg,sum=0,count=0;
    for(int i=0;i<n;i++)
    {
      sum+=ptr[i].price;
      count++;
    }
    avg=sum/count;
    printf("Average price of the books is=%d\n",avg);
}
void published_year(struct library_management*ptr,int year,int n)
{
          for(int i=0;i<n;i++)
          {
            if(ptr[i].yop==year)
            {
                printf("Books Published=%s in the year=%d\n",ptr[i].title,ptr[i].yop);
            }
            else
            {
                printf("No Books were published in the year=%d\n",ptr[i].yop);
            }
          }
          
}
void print_books_author(struct library_management*ptr,char s[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(ptr[i].author==s)
         printf("Name of Author=%s & His Written Book=%s\n",ptr[i].author,ptr[i].title);
    }
    
    printf("No Author is found with Name=%s\n",s);
}
void deletebook_id(struct library_management*ptr,int *n,int id)
{
    for(int i=0;i<*n;i++)
    {
        if(ptr[i].book_id==id)
        {
            free(ptr[i].title);
            for(int j=i;j<*n;j++)
            {
                ptr[j]=ptr[j+1];
            }
          (*n)--;
        }
    }
}
void add_books(struct library_management*ptr,int n)
{
    char *arr[n];
     for(int i=0;i<n;i++)
     {
        int n=strlen(ptr[i].title);
        arr[i]=(char*)malloc(n*sizeof(int));
        strcpy(arr[i],ptr[i].title);
     }
     for(int i=0;i<n;i++)
     {
        printf("%s\n",arr[i]);
        free(arr[i]);
     }
}
void print_books(struct library_management*ptr,int n)
{
    char *arr[n];
     for(int i=0;i<n;i++)
     {
        int n=strlen(ptr[i].title);
        arr[i]=(char*)malloc(n*sizeof(int));
        strcpy(arr[i],ptr[i].title);
     }
     for(int i=0;i<n;i++)
     {
        printf("%s\n",arr[i]);
        free(arr[i]);
     }
}
int main()
{
    int n;
    printf("Enter the Number of books\n");
    scanf("%d",&n);
    struct library_management lbm[n];
    for(int i=0;i<n;i++)
    {
        int a;
        printf("Enter Title length of the book\n");
        scanf("%d",&a);
        lbm[i].title=(char*)malloc(a*sizeof(char));
        scanf("%d %s %s %d %d",&lbm[i].book_id,lbm[i].title,lbm[i].author,&lbm[i].price,&lbm[i].yop);
    }
    printf("\n");
    int choice;
    do
    {
        printf("1-AddBooks\n2-Delete book by id\n3-Print all books\n4-Print books of an author\n5-Print Books published in a year\n6-Average Price of books\n");
        printf("Enter Choice:-\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            add_books(lbm,n);
            break;

            case 2:
            {
            int id;
            printf("Enter the book id\n");
            scanf("%d",&id);
            deletebook_id(lbm,&n,id);
            break;
            }
            case 3:
            print_books(lbm,n);
            break;

            case 4:
            {
            int a;
            printf("Enter the length of the name\n");
            scanf("%d",&a);
            char str[a];
            printf("Enter the searched string\n");
            scanf("%s",str);
            print_books_author(lbm,str,n); 
            break;
            }
           case 5:
            {
                int year;
                printf("Enter the year\n");
                scanf("%d",&year);
                published_year(lbm,year,n);
                break;
            }

            case 6:
            average_price(lbm,n);
            break;
             
            default:
            printf("Wrong Choice");


        }
    } while (choice!=7);
    
    for(int i=0;i<n;i++)
     free(lbm[i].title);   

     return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // for (int i = 0; i < n; i++) {
    //     printf("%d %s %s %d %d\n",
    //            (ptr + i)->book_id,
    //            (ptr + i)->title,
    //            (ptr + i)->author,
    //            (ptr + i)->price,
    //            (ptr + i)->yop);
    // }
    // for(int i=0;i<n;i++)
    // {
        
    //     if(ptr[i].book_id==102)
    //     {
    //        free(ptr[i].title);
    //        for(int j=i;j<n;j++)
    //        {
    //          ptr[j]=ptr[j+1];
    //        }
    //        n--;
    //     }
    // }
    //      for (int i = 0; i < n; i++) {
        // printf("%d %s %s %d %d\n",
        //        (ptr + i)->book_id,
        //        (ptr + i)->title,
        //        (ptr + i)->author,
        //        (ptr + i)->price,
        //        (ptr + i)->yop);
    
