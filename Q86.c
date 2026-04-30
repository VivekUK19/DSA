#include <stdio.h>

int integerSqrt(int n) {
    if (n < 2) return n;

    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        // Use long long for mid * mid to prevent overflow
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return (int)mid;
        } else if (square < n) {
            ans = (int)mid; // Update answer and search right
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1; // Search left
        }
    }
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", integerSqrt(n));
    }
    return 0;
}
