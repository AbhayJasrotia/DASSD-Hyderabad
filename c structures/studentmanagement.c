#include <stdio.h>
#include <limits.h>
#include <string.h>
struct student{
    int roll_no;
    char name[50];
    char sex[2];
    int exam_score;
};
void displayrecords(struct student *ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d %s %s %d\n",(ptr+i)->roll_no,
                                 (ptr+i)->name,
                                 (ptr+i)->sex,
                                 (ptr+i)->exam_score);
    }
}
int max_score(struct student *ptr,int n,char *s)
{
      int maxi=INT_MIN;
     for(int i=0;i<n;i++)
     {
         if((ptr+i)->exam_score>maxi){
         maxi=(ptr+i)->exam_score;
         strcpy(s,ptr[i].name);
     }
    }
     return maxi;
}
int low_score(struct student *ptr,int n,char *p)
{
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if((ptr+i)->exam_score<mini)
        {
           mini=(ptr+i)->exam_score;
           strcpy(p,ptr[i].name);
        }
    }
    return mini;

}
int main()
{
    int n;
    char max[100];
    char min[100];
    printf("Enter The Number of Student Details to be Shown:-\n");
    scanf("%d",&n);
    printf("Enter the details of the Students:-\n");
    struct student ob[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %s %s %d",&ob[i].roll_no,ob[i].name,ob[i].sex,&ob[i].exam_score);
    }
    displayrecords(ob,n);
    int high=max_score(ob,n,max);
    int low=low_score(ob,n,min);
    printf("Highest Marks score by an student is=%s and score is=%d\n",max,high);
    printf("Lowest Marks score by an student is=%s and score is=%d\n",min,low);
    return 0;
}