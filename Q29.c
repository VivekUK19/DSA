/* Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *create(int data){
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
node *list(node *tail, node *new){
    node *temp1;
    if(tail==NULL){
        tail=new;
        tail->next=new;
    }
    else{
        new->next=tail->next;
        tail->next=new;
    }
    return tail;
}
node *rotation(node *tail){
    node *temp, *current;
    temp=tail;
    current=tail->next;
    while(current->next!=tail){
        current=current->next;
    }
    temp->next=tail->next;
    current->next=temp;
    tail=current;
    return tail;
}
int main() {
    int n,i,temp,k,pos;
    node *tail, *ptr, *current;
    tail=NULL;
    printf("Enter the number of element in list:");
    scanf("%d",&n);
    printf("Enter the %d element in the list:",n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        ptr=create(temp);
        tail=list(tail,ptr);
    }
    current=tail->next;
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=tail->next);
    printf("\nEnter the no. of rotation:");
    scanf("%d",&pos);
    k=pos;
    if(pos>n){
        k=pos%n;
    }
    for(i=0;i<k;i++){
        tail=rotation(tail);
    }
    printf("Rotated List:");
    current=tail->next;
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=tail->next);
    return 0;
}