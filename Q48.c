#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int countLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0; 
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    } else {
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }
}
int main() {
    // Construct a sample binary tree
    //      25
    //     /  \
    //    27   19
    //   / \   / \
    //  17 91 13 55
    struct Node *root = newNode(25);
    root->left = newNode(27);
    root->right = newNode(19);
    root->left->left = newNode(17);
    root->left->right = newNode(91);
    root->right->left = newNode(13);
    root->right->right = newNode(55);
    printf("Number of leaf nodes in the tree are: %d\n", countLeafNodes(root));
    return 0;
}
