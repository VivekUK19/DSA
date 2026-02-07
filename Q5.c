/* A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include<stdio.h>
 int sorting(int *arr, int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return 0;
 }
int main(){
    int i,n1,n2,n3,count=0;
    int arr1[50];
    int arr2[50];
    int arr[100];
    printf("Enter the number of enteries in server log1:");
    scanf("%d",&n1);
    printf("Enter the %d arrival times from server 1:",n1);
    for(i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
     printf("Enter the number of enteries in server log2:");
    scanf("%d",&n2);
    printf("Enter the %d arrival times from server 2:",n2);
    for(i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<n1;i++){
       arr[count]=arr1[i];
       count++;
    }
    for(i=0;i<n2;i++){
       arr[count]=arr2[i];
       count++;
    }
    sorting(arr,count);
    for(i=0;i<count;i++){
      printf("%d ",arr[i]);
    }
    
}














