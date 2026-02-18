/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>
#include <stdlib.h>

void rotateArrayRight(int arr[], int n, int k) {
    k = k % n;
    if (k == 0) return;
    int *temp = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

int main() {
    int n,i,k;
    int arr[100];
    printf("Enter the number of element in the array:");
    scanf("%d",&n);
    printf("Enter the %d element of the array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of rotation:");
    scanf("%d",&k);
    rotateArrayRight(arr, n, k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
