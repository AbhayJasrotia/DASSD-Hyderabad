#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int *p;
};

int isFull(struct stack *ptr, int n) {
    return ptr->top >= n - 1;         
}

int isempty(struct stack *ptr) {
    return ptr->top == -1;
}

int push(struct stack *ptr, int n, int k) {
    if (isFull(ptr, n)) 
    return 1;      
    ptr->p[++(ptr->top)] = k;

    return 0;
}

int pop(struct stack *ptr, int key) {
    if (isempty(ptr)) 
    return 1;       

    for (int i = ptr->top; i >= 0; i--) 
    {
        if (ptr->p[i] == key) 
        {
            for (int j = i; j < ptr->top; j++) 
            {
                ptr->p[j] = ptr->p[j + 1];
            }
            ptr->top--;
            return 0;                  
        }
    }
    return 1;                          
}

void display(struct stack *ptr) {
    if (isempty(ptr)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = ptr->top; i >= 0; i--) {
        printf("%d ", ptr->p[i]);
    }
    printf("\n");
}

int main() {
    struct stack s;
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);

    s.top = -1;
    s.p =(int*) malloc(n * sizeof(int));


    int choice, val;
    do {
        printf("\n1 - Push\n2 - Pop by value\n3 - Display\n4 - Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &val);
                if (push(&s, n, val))
                    printf("Stack is full\n");
                else
                    printf("%d pushed\n", val);
                break;

            case 2:
                printf("Enter number to pop: ");
                scanf("%d", &val);
                if (pop(&s, val))
                    printf("Value not found or stack empty\n");
                else
                    printf("%d removed\n", val);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(s.p);
    return 0;
}
