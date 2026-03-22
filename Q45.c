/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3 */
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
int findHeight(struct Node* root) {
    if (root == NULL) return 0;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    return (lh > rh ? lh : rh) + 1;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (arr[0] == -1) {
        printf("0\n");
        return 0;
    }
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }
    printf("%d\n", findHeight(root));
    return 0;
}