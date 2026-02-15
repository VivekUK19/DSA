/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15*/
#include <stdio.h>
int main() {
    int n,m,i,sum=0,j;
    int arr[100][100];
    printf("Enter the rows and column of the matrix: ");
    scanf("%d %d",&n, &m);
    printf("Enter the element of the matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
          scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(i==j){
              sum+=arr[i][j];
        }
    }
}
    printf("Sum=%d.",sum);
    return 0;
}