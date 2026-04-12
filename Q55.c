/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct QueueNode {
    struct TreeNode *treeNode;
    struct QueueNode *next;
};
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, struct TreeNode *treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}
bool isEmpty(struct Queue* q) {
    return q->front == NULL;
}
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;
    while (i < n && !isEmpty(q)) {
        struct TreeNode* current = dequeue(q);
        if (i < n && arr[i] != -1) {
            current->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            current->left->val = arr[i];
            current->left->left = NULL;
            current->left->right = NULL;
            enqueue(q, current->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            current->right->val = arr[i];
            current->right->left = NULL;
            current->right->right = NULL;
            enqueue(q, current->right);
        }
        i++;
    }
    return root;
}
void rightView(struct TreeNode* root) {
    if (root == NULL) return;
    struct Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        int levelSize = 0;
        struct QueueNode* temp = q->front;
        while(temp != NULL) {
            levelSize++;
            temp = temp->next;
        }
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = dequeue(q);
            if (i == levelSize - 1) {
                printf("%d ", current->val);
            }
            if (current->left != NULL) {
                enqueue(q, current->left);
            }
            if (current->right != NULL) {
                enqueue(q, current->right);
            }
        }
    }
}
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 1;
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, N);
    rightView(root);
    return 0;
}
