/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
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
struct node *intersection(struct node *ptr1, struct node *ptr2){
    struct node *current;
    while(ptr1!=NULL){
    current=ptr2;
        while(current!=NULL){
            if(ptr1->data==current->data){
                return ptr1;
            }
            current=current->next;
    }
    ptr1=ptr1->next;
    }
    return NULL;
}
int main() {
    int n,m,i,temp;
    struct node *head1, *head2, *ptr, *current;
    head1=NULL;
    head2=NULL;
    printf("Enter the number of the nodes:");
    scanf("%d",&n);
    printf("Enter the %d element of the nodes:");
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        ptr=create(temp);
        head1=create_list(head1,ptr);
    }
    printf("Enter the number of the nodes:");
    scanf("%d",&m);
    printf("Enter the %d element of the nodes:");
    for(i=0;i<m;i++){
        scanf("%d",&temp);
        ptr=create(temp);
        head2=create_list(head2,ptr);
    }
    ptr=intersection(head1,head2);
    if(ptr==NULL){
        printf("Intersection is not found.");
    }
    else{
        printf("The intersection is %d",ptr->data);
    }
    return 0;
}