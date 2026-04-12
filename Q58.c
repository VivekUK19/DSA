/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>
int preIndex = 0;
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}
void printPostOrder(int in[], int pre[], int inStart, int inEnd) {
    if (inStart > inEnd) return;
    int rootVal = pre[preIndex++];
    int inIndex = search(in, inStart, inEnd, rootVal);
    printPostOrder(in, pre, inStart, inIndex - 1);
    printPostOrder(in, pre, inIndex + 1, inEnd);
    printf("%d ", rootVal);
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int pre[n], in[n];
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    printPostOrder(in, pre, 0, n - 1);
    printf("\n");
    return 0;
}
