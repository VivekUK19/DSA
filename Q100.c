#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* count, Element* temp) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      
    int right_count = 0; 

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            right_count++;
            temp[k++] = arr[j++];
        } else {
            count[arr[i].index] += right_count;
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid) {
        count[arr[i].index] += right_count;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) arr[i] = temp[i];
}
void solve(Element* arr, int left, int right, int* count, Element* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        solve(arr, left, mid, count, temp);
        solve(arr, mid + 1, right, count, temp);
        merge(arr, left, mid, right, count, temp);
    }
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* count = (int*)calloc(numsSize, sizeof(int));
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    Element* temp = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    solve(arr, 0, numsSize - 1, count, temp);
    *returnSize = numsSize;
    free(arr);
    free(temp);
    return count;
}
