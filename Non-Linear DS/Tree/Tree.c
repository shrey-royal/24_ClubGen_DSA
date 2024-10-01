#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node* node;

struct Node {
    int key;
    node left;
    node right;
};

node createNode(int key) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node insert(node root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(node root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(node root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

node search(node root, int key) {
    while (root != NULL && root->key != key) {
        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return root;
}

int height(node root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

node deleteNode(node root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            node temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node temp = root->left;
            free(root);
            return temp;
        }

        node temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void findMinMax(node root, int* min, int* max) {
    node temp = root;
    while (root->left != NULL) root = root->left;
    *min = root->key;

    while (temp->right != NULL) temp = temp->right;
    *max = temp->key;
}

void pruneTree(node* root) {
    if (*root != NULL) {
        pruneTree(&((*root)->left));
        pruneTree(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}

void printTree(node root, int space) {
    if (root == NULL) return;

    space += 4;
    printTree(root->right, space);

    for (int i = 4; i < space; i++) printf(" ");
    printf("%d\n", root->key);

    printTree(root->left, space);
}

int main() {    // 1 25 1 35 1 18 1 22 1 43 1 8 1 69 1 27
    node root = NULL;
    int choice, key, min, max;

    do {
        system("cls");
        printTree(root, 0);
        printf("\n\nBinary Tree Operations Menu\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Height\n");
        printf("7. Delete\n");
        printf("8. Find Min and Max\n");
        printf("9. Prune Tree\n");
        printf("10. Display Tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("\nInorder Traversal : ");
                inorder(root);
                printf("\n");
                system("pause");
                break;

            case 3:
                printf("\nPreorder Traversal : ");
                preorder(root);
                printf("\n");
                system("pause");
                break;

            case 4:
                printf("\nPostorder Traversal : ");
                postorder(root);
                printf("\n");
                system("pause");
                break;

            case 5:
                printf("\nPlease enter a value to search: ");
                scanf("%d", &key);

                if (search(root, key) != NULL) {
                    printf("\nKey %d found in the tree.\n", key);
                } else {
                    printf("\nKey %d not found in the tree.\n", key);
                }
                system("pause");
                break;

            case 6:
                printf("\nHeight of the tree: %d\n", height(root));
                system("pause");
                break;

            case 7:
                printf("\nEnter the value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 8:
                min = INT_MAX;
                max = INT_MIN;
                findMinMax(root, &min, &max);
                printf("\nMinimum value in the tree: %d", min);
                printf("\nMaximum value in the tree: %d\n", max);
                system("pause");
                break;

            case 9:
                pruneTree(&root);
                break;

            case 10:
                printTree(root, 0);
                printf("\n");
                system("pause");
                break;

            case 0:
                printf("Exiting the program...\n");
                break;
        }
    } while (choice != 0);

    return 0;
}