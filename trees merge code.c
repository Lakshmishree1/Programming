#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

struct Node* findMinimumNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinimumNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void postOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    postOrder(root->left, fp);
    postOrder(root->right, fp);
    fprintf(fp, "%d ", root->data);
}

void preOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    fprintf(fp, "%d ", root->data);
    preOrder(root->left, fp);
    preOrder(root->right, fp);
}

void inOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    inOrder(root->left, fp);
    fprintf(fp, "%d ", root->data);
    inOrder(root->right, fp);
}

void levelOrder(struct Node* root, FILE* fp) {
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = -1;
    int rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct Node* temp = queue[++front];
        fprintf(fp, "%d ", temp->data);

        if (temp->left)
            queue[++rear] = temp->left;
        if (temp->right)
            queue[++rear] = temp->right;
    }
}

void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a random number\n");
    printf("2. Delete a node\n");
    printf("3. Display tree traversals\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    srand(time(NULL));  // Initialize the random number generator

    FILE* fp = fopen("output.txt", "w");  // Open the file in write mode

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                data = rand() % 100;  // Generate a random number between 0 and 99
                printf("Inserting random number: %d\n", data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted successfully.\n");
                break;
            case 3:
                printf("Post-order traversal: ");
                postOrder(root, fp);
                fprintf(fp, "\n");

                printf("Pre-order traversal: ");
                preOrder(root, fp);
                fprintf(fp, "\n");

                printf("In-order traversal: ");
                inOrder(root, fp);
                fprintf(fp, "\n");

                printf("Level-order traversal: ");
                levelOrder(root, fp);
                fprintf(fp, "\n");
                break;
            case 4:
                fclose(fp);  // Close the file
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
