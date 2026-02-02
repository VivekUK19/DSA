/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/
#include <stdio.h>
int main() {
	int n,i,pos;
	printf("Enter the no of the element:");//No of element
	scanf("%d",&n);
	int arr[n];
	printf("Enter the %d no of element:");//Initialzing array
	for(i=0;i<n;i++){
	    scanf("%d",&arr[i]);
	}
	printf("Enter the position form which you have to delete element:");//Position from you want to delete element 
	scanf("%d",&pos);
	for(i=pos;i<n;i++){//Deleting element form the array
	    arr[i-1]=arr[i];
	}
	n--;
	for(i=0;i<n;i++){//Printing ans array
	    printf("%d ",arr[i]);
	}
	return 0;
}
