/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{//initializing struct for polynomial
    int expo;
    int coff;
    struct node *next;
}node;
node *create(int data, int co){//node for polynomail
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->expo=data;
    ptr->coff=co;
    ptr->next=NULL;
    return ptr;
}
void swap(node *a, node *b){//sorting
    int temp=a->coff;
    int temp1=a->expo;
    a->coff=b->coff;
    a->expo=b->expo;
    b->coff=temp;
    b->expo=temp1;
} 
void sorting(node *head){
    int swapped;
    node *ptr, *ptr1;
    ptr1=NULL;
    do{
        swapped=0;
        ptr=head;
        while(ptr->next != ptr1){
            if(ptr->expo<ptr->next->expo){
                swap(ptr,ptr->next);
                swapped=1;
            }
            ptr=ptr->next;
        }
        ptr1=ptr;
    }while(swapped);
}
int main(){//main function
    int n,i,exp,coffe;
    node *head,*temp,*current;
    printf("Enter the highest degree of the polynomial:");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        printf("Enter the exponent of the variable:");
        scanf("%d",&exp);
          if(exp>n || exp<0){
            printf("Invalid input\n");
            i--;
            continue;
        }
        printf("Enter the coefficient of the variable:");
        scanf("%d",&coffe);
        temp=create(exp,coffe);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
    }
}
    sorting(head);
    current=head;
    while(current!=NULL){
        printf("%dx^%d +",current->coff,current->expo);
        current=current->next;
    }
    return 0;
}