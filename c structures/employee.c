#include <stdio.h>

struct employee {
    int  id;
    char name[100];
    char gender[3];    
    int  age;
    long int salary;
};

void insert(struct employee ptr[], int n) {
    printf("Enter the details of the employees:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %s %d %ld",
              &ptr[i].id,
              ptr[i].name,
              ptr[i].gender,
              &ptr[i].age,
              &ptr[i].salary);
    }
    printf("\n");
}

void display(struct employee *ptr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %s %d %ld\n",
               (ptr + i)->id,
               (ptr + i)->name,
               (ptr + i)->gender,
               (ptr + i)->age,
               (ptr + i)->salary);
    }
}

int main() {
    int n;
    printf("Enter the number of employees:\n");
    scanf("%d", &n);

    struct employee s1[n];
    insert(s1, n);
    display(s1, n);

    return 0;
}
