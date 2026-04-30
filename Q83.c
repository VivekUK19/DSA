#include<stdio.h>
#define MAX 100
int arr[MAX];
void swap(int *a, int *b){
    int c=*b;
    *b=*a;
    *a=c;
}
void selection_sort(int n){
    int i,j,min_index;
    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
            min_index=j;
        }
    if(i!=min_index){
        swap(&arr[i],&arr[min_index]);
    }
    }
    }
}
int binary_search(int low, int high, int key){
    if(low>high)
    {
        return -1;
    }
    int mid=(low+high)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binary_search(low,mid-1,key);
    }
    else if(arr[mid]<key){
        return binary_search(mid+1,high,key);
    }
}
int main(){
    int n,i,key,index;
    printf("Enter the number of the element:");
    scanf("%d",&n);
    printf("Enter the %d element of the array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection_sort(n);
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the key element:");
    scanf("%d",&key);
    index=binary_search(0,n-1,key);
    if(index == -1){
        printf("Element not found.");
    }
    else{
        printf("Elemet found at %d index.",index);
    }
    return 0;
}