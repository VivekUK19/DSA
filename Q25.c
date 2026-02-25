/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create_node(int data){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}
struct node *create_list(struct node *head, struct node *new){
    if (head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head=new;
    }
    return head;
}
int main(){
    int n,i,key,temp,count=0;
    struct node *head, *current, *temp_list;
    head=NULL;
    printf("Enter the no of element in the List:");
    scanf("%d",&n);
    printf("Enter the %d element of the List:",n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        temp_list=(struct node*)malloc(sizeof(struct node));
        temp_list=create_node(temp);
        head=create_list(head,temp_list);
    }
    printf("Enter the key element you want to find:");
    scanf("%d",&key);
    current=head;
    while(current!=NULL){
        if(current->data==key){
            count++;
        }
        current=current->next;
    }
    if(count==0){
        printf("Key not find.");
    }
    else{
        printf("Key element %d find %d time.",key,count);
    }
}