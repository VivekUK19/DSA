/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <stdio.h>

int main() {
    int m,n,i,j;
    int arr[100][100];
    printf("Enter the no. of the rows and column:");
    scanf("%d %d",&m,&n);
    printf("Enter the %d element of the array:"m*n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    printf("Spiral Traversal: ");
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            printf("%d ", arr[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            printf("%d ", arr[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }
    printf("\n");
    return 0;
}