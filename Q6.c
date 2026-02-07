/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}
int main() {
    int arr[100]; 
    int n,i;
    printf("Enter the number of the element: ");
    scanf("%d",&n);
    printf("Enter the %d element of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    n=removeDuplicates(arr,n);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
















