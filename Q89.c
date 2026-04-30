#include <stdio.h>
#include <stdbool.h>

// Function to check if a "max_limit" is feasible for m students
bool isPossible(int pages[], int n, int m, int max_limit) {
    int studentCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than our limit, it's impossible
        if (pages[i] > max_limit) return false;

        if (currentSum + pages[i] <= max_limit) {
            currentSum += pages[i];
        } else {
            // Assign to the next student
            studentCount++;
            currentSum = pages[i];
            
            if (studentCount > m) return false;
        }
    }
    return true;
}

int allocateBooks(int pages[], int n, int m) {
    if (m > n) return -1; // More students than books

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > low) low = pages[i]; // Start low at max pages of a single book
        high += pages[i];                  // Start high at sum of all pages
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pages, n, m, mid)) {
            result = mid;     // Try to find a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;    // Increase the limit
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int pages[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("%d\n", allocateBooks(pages, n, m));

    return 0;
}
