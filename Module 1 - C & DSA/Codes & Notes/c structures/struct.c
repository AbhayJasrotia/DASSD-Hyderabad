#include <stdio.h>
struct student{
  char *name;
  int roll;
  float cgpa;
};
int main()
{
    struct student ob[2]={{"prantik",101,8.7},{"Jogn",102,6.5}};
    struct student *ptr=&ob[0];
    printf("%d\n",sizeof(ob));
    //printf("%d\n",ptr->roll);//(*ptr).roll=ob.roll
    //printf("%.2f",ptr->cgpa);//(*ptr).cgpa=ob.cgpa
    for(int i=0;i<2;i++)
    {
         printf("%s %d %.2f\n",ptr[i].name,ptr[i].roll,ptr[i].cgpa);
    }
    return 0;

    // ob.name[0]="Prantik";
    // ob.name[1]="John";
    // ob.roll=30;
    // ob.cgpa=12.5;
}
  

