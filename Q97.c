#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};
int compareStart(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}
int minMeetingRooms(struct Interval* intervals, int n) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(struct Interval), compareStart);
    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    heap[heapSize++] = intervals[0].end;

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= heap[0]) {
            heap[0] = intervals[i].end;
        } else {
            heap[heapSize++] = intervals[i].end;
        }
        for (int j = (heapSize / 2) - 1; j >= 0; j--) {
            minHeapify(heap, heapSize, j);
        }
    }
    free(heap);
    return heapSize; 
}
int main() {
    struct Interval apps[] = {{0, 30}, {5, 10}, {15, 20}};
    printf("Minimum rooms: %d\n", minMeetingRooms(apps, 3)); 
    return 0;
}
