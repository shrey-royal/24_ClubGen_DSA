#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int data) {    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    printf("\nList: ==> ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position, key;
    struct Node* head = NULL;

    while (1) {
        system("cls");
        printList(head);

        printf("\n\n\n1. Insert at beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Search By Value");
        printf("\n5. Length of the list");
        printf("\n6. Reverse the List");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete at end");
        printf("\n9. Delete at Position");
        printf("\n10. Print list from beginning");
        printf("\n11. Print list from end");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;

        // case 2:
        //     printf("\nEnter the data: ");
        //     scanf("%d", &data);
        //     InsertAtEnd(&head, data);
        //     break;

        // case 3:
        //     printf("\nEnter the position: ");
        //     scanf("%d", &position);
        //     printf("\nEnter the data: ");
        //     scanf("%d", &data);
        //     InsertAtPos(&head, data, position);
        //     break;

        // case 4:
        //     printf("\nEnter the key to search from the list: ");
        //     scanf("%d", &key);
        //     searchByValue(head, key) ? printf("\n%d present in the list...", key) : printf("\n%d is not present in the list...", key);
        //     break;

        // case 5:
        //     printf("\nLength of the list: %d\n", getLength(head));
        //     break;

        // case 6:
        //     reverseList(&head);
        //     break;

        // case 7:
        //     deleteAtBeginning(&head);
        //     break;

        // case 8:
        //     deleteAtEnd(&head);
        //     break;

        // case 9:
        //     printf("\nEnter the position to delete the node: ");
        //     scanf("%d", &position);
        //     deleteAtPosition(&head, position);
        //     break;

        case 10:
            printList(head);
            break;

        // case 11:
        //     printf("\nList from End: ");
        //     PrintFromEnd(head);
        //     printf("NULL\n");
        //     break;

        case 0:
            printf("\nExiting...\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}