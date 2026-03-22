/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
struct Node* buildTree() {
    int val;
    printf("Enter root data (-1 for NULL): ");
    scanf("%d", &val);
    if (val == -1) return NULL;
    struct Node* root = newNode(val);
    struct Node* queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        int leftVal, rightVal;
        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &leftVal);
        if (leftVal != -1) {
            current->left = newNode(leftVal);
            queue[rear++] = current->left;
        }
        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &rightVal);
        if (rightVal != -1) {
            current->right = newNode(rightVal);
            queue[rear++] = current->right;
        }
    }
    return root;
}
void printLevelOrder(struct Node* root) {
    if (!root) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    printf("\nLevel Order Traversal: ");
    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    printf("\n");
}
int main() {
    struct Node* root = buildTree();
    printLevelOrder(root);
    return 0;
}
