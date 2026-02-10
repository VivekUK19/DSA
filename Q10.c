// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards
#include <stdio.h>
#include <string.h>

int isPalindrome(char* str) {
    int length = strlen(str);
    int left = 0;
    int right = length - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
int main() {
    char str[100]; 
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } 
    else {
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}
