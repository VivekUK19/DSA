#include<stdio.h>
int main(){
    int n,pos,x,i;
    printf("Enter the number of the element:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d element of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the position in which you want to add element:\n");
    scanf("%d",&pos);
    printf("Enter the element:\n");
    scanf("%d",&x);
    n++;
    for(i=n-1;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=x;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}