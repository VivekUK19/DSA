/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct QNode {
    struct TreeNode *treeNode;
    struct QNode *next;
};
struct Queue {
    struct QNode *front, *rear;
};
struct QNode* createQNode(struct TreeNode *treeNode) {
    struct QNode* qNode = (struct QNode*)malloc(sizeof(struct QNode));
    qNode->treeNode = treeNode;
    qNode->next = NULL;
    return qNode;
}
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, struct TreeNode *treeNode) {
    struct QNode* temp = createQNode(treeNode);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QNode* temp = q->front;
    struct TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}
struct TreeNode* buildTreeFromLevelOrder(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[0];
    root->left = NULL;
    root->right = NULL;
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;
    while (i < n && q->front != NULL) {
        struct TreeNode* current = dequeue(q);
        if (i < n && arr[i] != -1) {
            struct TreeNode* leftChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            leftChild->val = arr[i];
            leftChild->left = NULL;
            leftChild->right = NULL;
            current->left = leftChild;
            enqueue(q, leftChild);
        }
        i++;
        if (i < n && arr[i] != -1) {
            struct TreeNode* rightChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            rightChild->val = arr[i];
            rightChild->left = NULL;
            rightChild->right = NULL;
            current->right = rightChild;
            enqueue(q, rightChild);
        }
        i++;
    }
    return root;
}
bool areMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) && 
           areMirror(t1->left, t2->right) && 
           areMirror(t1->right, t2->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return areMirror(root->left, root->right);
}
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 1;
    int *arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }
    struct TreeNode* root = buildTreeFromLevelOrder(arr, N);
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(arr);
    return 0;
}
