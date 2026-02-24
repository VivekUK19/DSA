/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}
void deleteKey(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("\nSuccess: Deleted first occurrence of key %d.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nNotice: Key %d not found in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void printList(struct Node* head) {
    struct Node *node;
    if (node == NULL) {
        printf("List is currently empty.\n");
        return;
    }
    printf("Current List: ");
    node=head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, val, key;
    struct Node* head = NULL;
    printf("Enter number of elements to add: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        append(&head, val);
    }

    printList(head);

    printf("\nEnter the key value you wish to delete: ");
    scanf("%d", &key);

    deleteKey(&head, key);
    printList(head);

    return 0;
}
