#include <stdio.h>
int isPossible(int boards[], int n, int k, int limit) {
    int paintersUsed = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] <= limit) {
            currentSum += boards[i];
        } else {
            paintersUsed++;
            currentSum = boards[i];
            if (paintersUsed > k) return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    int max_val = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > max_val) max_val = boards[i];
        sum += boards[i];
    }

    long long low = max_val;
    long long high = sum;
    long long result = sum;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;  
            high = mid - 1;
        } else {
            low = mid + 1; 
        }
    }
    printf("%lld\n", result);
    return 0;
}
