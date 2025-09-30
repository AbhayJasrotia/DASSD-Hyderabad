#include <stdio.h>

struct employee {
    int roll;
    char name[100];                  //here u can't access char*name as because memory is accessed at runtime so allocation of storage
                                    // is necessary .
                                    // so how can we access?
                                    //Ans:- Using runtime function malloc.
    float marks;
};
void display(struct employee *ptr,int n){
         for(int i=0;i<n;i++)
         {
            printf("%d %s %.2f\n", ptr[i].roll, ptr[i].name, ptr[i].marks);
            printf("%d %s %.2f\n", (ptr+i)->roll, (ptr+i)->name,(ptr+i)->marks);
            //Both are feasible at printing.
    // }
         }
}
int main() {
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);

    struct employee as[n];

    for (int i = 0; i < n; i++) {
        printf("Enter roll, name, marks:\n");
        scanf("%d %s %f", &as[i].roll, as[i].name, &as[i].marks);
    }

    // printf("\nEmployee details:\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d %s %.2f\n", as[i].roll, as[i].name, as[i].marks);
    // }
      display(as,n);
    return 0;
}
