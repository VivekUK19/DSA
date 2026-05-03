#include <stdio.h>
#include <stdlib.h>
struct Node {
    float data;
    struct Node* next;
};
struct Node* insertionSort(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* sorted = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        if (!sorted || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next;
    }
    return sorted;
}
void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i]; // Index in bucket
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); 
        }
    }
    free(buckets);
}
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) printf("%f ", arr[i]);
    return 0;
}
