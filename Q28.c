/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
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
    node *current;
    if(tail==NULL){
        tail=new;
        tail->next=new;
    }
    else{
        current=tail->next;
        new->next=current;
        tail->next=new;
    }
    return tail;
}
int main() {
    int n,i,temp;
    node *tail, *ptr, *current;
    tail=NULL;
    printf("Enter the number of element in list:");
    scanf("%d",&n);
    printf("Enter the %d element in the list:");
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
    return 0;
}