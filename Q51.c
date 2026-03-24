#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
int findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data) {
            root = root->left;
        }
        else if (n1 > root->data && n2 > root->data) {
            root = root->right;
        }
        else {
            return root->data;
        }
    }
    return -1;
}
int main() {
    int N, i, nodeValue1, nodeValue2, lcaValue;
    struct Node* root = NULL;
    if (scanf("%d", &N) != 1) return 1;
    for (i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }
    if (scanf("%d %d", &nodeValue1, &nodeValue2) != 2) return 1;
    lcaValue = findLCA(root, nodeValue1, nodeValue2);
    printf("%d\n", lcaValue);
    return 0;
}
