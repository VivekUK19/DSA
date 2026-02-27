/*problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(int data){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}
struct node *create_list(struct node *head, struct node *new){
    if (head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head->prev=new;
        head=new;
    }
    return head;
}
int main() {
    int n,i,temp;
    struct node *head, *ptr, *current;
    head=NULL;
    printf("Enter the number of the nodes:");
    scanf("%d",&n);
    printf("Enter the %d element of the nodes:");
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        ptr=create(temp);
        head=create_list(head,ptr);
    }
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    while(current!=NULL){
        printf("%d ", current->data);
        current=current->prev;
    }
    return 0;
}