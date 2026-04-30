#include<stdio.h>
#define MAX 100
int arr[MAX];
void swap(int *a, int *b){
    int c=*b;
    *b=*a;
    *a=c;
}
void insertion_sort(int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }}
int main(){
    int n,i;
    printf("Enter the number of the element:");
    scanf("%d",&n);
    printf("Enter the %d element of the array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(n);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}