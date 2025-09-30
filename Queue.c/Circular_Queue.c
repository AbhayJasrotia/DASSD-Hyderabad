#include <stdio.h>
#include <stdlib.h>

struct circular_queue {
    int front;
    int rear;
    int *p;
};

int isfull(struct circular_queue *ptr, int n) {
    return (ptr->rear + 1) % n == ptr->front;
}

int isempty(struct circular_queue *ptr) {
    return ptr->front ==-1;
}

int enqueue(struct circular_queue *ptr, int a, int n) {
    if (isfull(ptr, n))
        return 1;

      if(ptr->front==-1)
      ptr->front=0;
        
    
    ptr->rear = (ptr->rear + 1) % n;
    ptr->p[ptr->rear] = a;
    return 0;
}

int dequeue(struct circular_queue *ptr, int n) {
    if (isempty(ptr))
        return 1;

    if (ptr->front == ptr->rear) 
    {    
        ptr->front = -1;
        ptr->rear  = -1;
    } else {
        ptr->front = (ptr->front + 1) % n;
    }
    return 0;
}

void display(struct circular_queue *ptr, int n) {
    if (isempty(ptr)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:");
    int i = ptr->front;
    while (1) 
    {
        printf("%d ", ptr->p[i]);
        if (i == ptr->rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

int main() {
    struct circular_queue q;
    q.front = -1;
    q.rear  = -1;

    int n;
    printf("Enter the size of the queue\n");
    scanf("%d", &n);

    q.p = (int*)malloc(n * sizeof(int));
    if (!q.p) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int a;
                printf("Enter element to enqueue: ");
                scanf("%d", &a);
                if (enqueue(&q, a, n))
                    printf("Queue is Full\n");
                else
                    printf("%d is pushed into Queue\n", a);
                break;
            }
            case 2:
                if (dequeue(&q, n))
                    printf("Queue is Empty\n");
                else
                    printf("Element dequeued\n");
                break;

            case 3:
                display(&q, n);
                break;

            case 4:
                free(q.p);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Wrong Choice\n");
        }
    }
}
