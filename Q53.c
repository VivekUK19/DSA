/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
typedef struct QueueItem {
    TreeNode* node;
    int hd;
} QueueItem;
QueueItem queue[10000];
int front = 0, rear = 0;
void enqueue(TreeNode* node, int hd) {
    if (rear < 10000) {
        queue[rear].node = node;
        queue[rear].hd = hd;
        rear++;
    }
}
QueueItem dequeue() {
    if (front < rear) {
        return queue[front++];
    }
    return (QueueItem){NULL, 0};
}
int isQueueEmpty() {
    return front == rear;
}
TreeNode* buildTree(int* nodes, int n) {
    if (n == 0 || nodes[0] == -1) return NULL;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = nodes[0];
    root->left = NULL;
    root->right = NULL;    
    front = 0; rear = 0; 
    enqueue(root, 0); 
    int i = 1;
    while (i < n && !isQueueEmpty()) {
        QueueItem current = dequeue();
        TreeNode* parent = current.node;
        if (i < n && nodes[i] != -1) {
            parent->left = (TreeNode*)malloc(sizeof(TreeNode));
            parent->left->val = nodes[i];
            parent->left->left = NULL;
            parent->left->right = NULL;
            enqueue(parent->left, 0);
        }
        i++;
        if (i < n && nodes[i] != -1) {
            parent->right = (TreeNode*)malloc(sizeof(TreeNode));
            parent->right->val = nodes[i];
            parent->right->left = NULL;
            parent->right->right = NULL;
            enqueue(parent->right, 0);
        }
        i++;
    }
    front = 0; rear = 0;
    return root;
}
void findMinMaxHD(TreeNode* node, int* minHD, int* maxHD, int currentHD) {
    if (node == NULL) return;
    if (currentHD < *minHD) *minHD = currentHD;
    if (currentHD > *maxHD) *maxHD = currentHD;
    findMinMaxHD(node->left, minHD, maxHD, currentHD - 1);
    findMinMaxHD(node->right, minHD, maxHD, currentHD + 1);
}
void printVerticalLine(TreeNode* root, int lineHD) {
    if (root == NULL) return;
    front = 0; rear = 0; 
    enqueue(root, 0);
    while (!isQueueEmpty()) {
        QueueItem current = dequeue();
        TreeNode* temp = current.node;
        int hd = current.hd;

        if (hd == lineHD) {
            printf("%d ", temp->val);
        }
        if (temp->left) enqueue(temp->left, hd - 1);
        if (temp->right) enqueue(temp->right, hd + 1);
    }
}
void verticalOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    int minHD = 0, maxHD = 0;
    findMinMaxHD(root, &minHD, &maxHD, 0); 
    for (int lineHD = minHD; lineHD <= maxHD; lineHD++) {
        printVerticalLine(root, lineHD); 
    }
}

// Driver program
int main() {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) return 1;
    int* nodes = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &nodes[i]);
    }
    TreeNode* root = buildTree(nodes, N);
    verticalOrderTraversal(root);
    printf("\n");
    free(nodes);
    return 0;
}
