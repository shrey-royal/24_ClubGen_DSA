#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct Dequeue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initDequeue(struct Dequeue *dq) {
    dq->front = dq->rear = -1;
}

int isFull(struct Dequeue *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(struct Dequeue *dq) {
    return dq->front == -1;
}

void insertFront(struct Dequeue *dq, int value) {
    if (isFull(dq)) printf("\nDeuqeue is Full!\n");
    else {
        if (dq->front == -1) {
            dq->front = dq->rear = 0;
        } else if (dq->front == 0) {
            dq->front = MAX_SIZE - 1;
        } else {
            dq->front--;
        }
        dq->items[dq->front] = value;
        // printf("\nInserted %d at the front", value);
    }
}

void insertRear(struct Dequeue *dq, int value) {
    if (isFull(dq)) printf("\nDeuqeue is Full!\n");
    else {
        if (dq->front == -1) {
            dq->front = dq->rear = 0;
        } else if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
        dq->items[dq->rear] = value;
        // printf("\nInserted %d at the rear", value);
    }
}

void deleteFront(struct Dequeue *dq) {
    if (isEmpty(dq)) printf("\nDeuqeue is Empty!\n");
    else {
        printf("\nDeleted %d from the front", dq->items[dq->front]);
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;
        } else if (dq->front == MAX_SIZE - 1) {
            dq->front = 0;
        } else {
            dq->front++;
        }
    }
}

void deleteRear(struct Dequeue *dq) {
    if (isEmpty(dq)) printf("\nDeuqeue is Empty!\n");
    else {
        printf("\nDeleted %d from the rear", dq->items[dq->rear]);
        if (dq->front == dq->rear) {
            dq->front = dq->rear = -1;
        } else if (dq->rear == 0) {
            dq->rear = MAX_SIZE - 1;
        } else {
            dq->rear--;
        }
    }
}

void peekFront(struct Dequeue *dq) {
    if (isEmpty(dq)) printf("\nDequeue is Empty!\n");
    else {
        printf("\nFront element: %d\n", dq->items[dq->front]);
    }
}

void peekRear(struct Dequeue *dq) {
    if (isEmpty(dq)) printf("\nDequeue is Empty!\n");
    else {
        printf("\nRear element: %d\n", dq->items[dq->rear]);
    }
}

void display(struct Dequeue *dq) {
    if (isEmpty(dq)) printf("\nDequeue is Empty!\n");
    else {
        printf("Deque elements: ");
        int i = dq->front;
        while (1) {
            printf("%d ", dq->items[i]);
            if (i == dq->rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    struct Dequeue dq;
    initDequeue(&dq);

    int choice, value;

    do {
        system("cls");
        display(&dq);
        printf("\n\n\nDequeue Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. Display Dequeue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                peekFront(&dq);
                system("pause");
                break;
            case 6:
                peekRear(&dq);
                system("pause");
                break;
            case 7:
                display(&dq);
                system("pause");
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    } while (choice != 8);

    return 0;
}