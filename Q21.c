
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* reverse(struct node *head){
    struct node *prev, *current, *n;
    prev=NULL;
    current=head;
    n=NULL;
    while(current!=NULL){
        n=current->next;
        current->next=prev;
        prev=current;
        current=n;
    }
    return prev;
}
int main(){
    int n,value,i=1;
    struct node *head, *ptr, *current;
    head=NULL;
    printf("Enter the number of element of the list:");
    scanf("%d",&n);
    printf("Enter the value:");
    for(i-0;i<=n;i++){
        ptr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        ptr->data=value;
        ptr->next=NULL;
        if(head==NULL){
            head=ptr;
        }
        else{
            ptr->next=head;
            head=ptr;
        }
}
    head=reverse(head);
    current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    return 0;
}