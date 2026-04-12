/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (head < tail && i < n) {
        struct TreeNode* current = queue[head++];
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[tail++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[tail++] = current->right;
        }
        i++;
    }
    return root;
}
void zigzagLevelOrder(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* q[1000]; 
    int head = 0, tail = 0;
    q[tail++] = root;
    int leftToRight = 1; 
    while (head < tail) {
        int levelSize = tail - head;
        int currentLevel[levelSize];
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = q[head++];
            if (leftToRight) {
                currentLevel[i] = current->val;
            } else {
                currentLevel[levelSize - 1 - i] = current->val;
            }
            if (current->left) q[tail++] = current->left;
            if (current->right) q[tail++] = current->right;
        }
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", currentLevel[i]);
        }
        leftToRight = !leftToRight;
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
    zigzagLevelOrder(root);
    printf("\n");
    return 0;
}
