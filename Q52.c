#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
TreeNode* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;
    TreeNode* root = createNode(arr[0]);
    TreeNode* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;
    for (int i = 1; i < n && head < tail; ) {
        TreeNode* curr = queue[head++];
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[tail++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[tail++] = curr->right;
        }
        i++;
    }
    return root;
}
TreeNode* findLCA(TreeNode* root, int p_val, int q_val) {
    if (root == NULL || root->data == p_val || root->data == q_val) {
        return root;
    }
    TreeNode* left_lca = findLCA(root->left, p_val, q_val);
    TreeNode* right_lca = findLCA(root->right, p_val, q_val);
    if (left_lca != NULL && right_lca != NULL) {
        return root;
    }
    return (left_lca != NULL) ? left_lca : right_lca;
}
int main() {
    int N;
    if (scanf("%d", &N) != 1) return 1;
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int node1_val, node2_val;
    if (scanf("%d %d", &node1_val, &node2_val) != 2) return 1;
    TreeNode* root = buildTree(arr, N);
    TreeNode* lca_node = findLCA(root, node1_val, node2_val);
    if (lca_node != NULL) {
        printf("%d\n", lca_node->data);
    } else {
        printf("LCA not found or nodes not in tree.\n");
    }
    return 0;
}
