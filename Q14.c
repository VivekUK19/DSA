/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>
#include<stdlib.h>
int main() {
    int n,i,count=0,j;
    int arr[100][100];
    printf("Enter the rows and column of the sqaured matrix: ");
    scanf("%d",&n);
    printf("Enter the element of the matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(i==j){
              if(arr[i][j]!=1){
                  count++;
                  exit(0);
              }
              if(i!=j){
              if(arr[i][j]!=0){
                  count++;
                  exit(0);
              }
          }
        }
    }
}
if(count==0){
    printf("Identity matrix.");
}
else{
    printf("Not identity matrix.");
}
    return 0;
}