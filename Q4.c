/*Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1
*/
#include <stdio.h>
int main() {
    int i,n,temp,mid;
    int arr[100];
    int a[50];
    printf("Enter the no of the element: ");
    scanf("%d",&n);
    temp=n-1;
    mid=n/2;
    printf("Enter the %d element of the array: ");
    for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[temp]);
        temp--;
    }
    return 0;
}