/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,k,l,i,j,temp;
    int arr[100];
    int sum;
    printf("Enter the number of the element in the array:");
    scanf("%d",&n);
    printf("Enter the %d element of the array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sum=arr[0]+arr[1];
    k=arr[0];
    l=arr[1];
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            temp=arr[i]+arr[j];
            if(abs(temp)<abs(sum)){
                sum=temp;
                k=arr[i];
                l=arr[j];
            }
        }
    }
    printf("The Outcome: %d %d",k,l);
    return 0;
}



















