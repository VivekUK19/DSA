#include <stdio.h>
int main() {
    char s[1001];
    if (scanf("%1000s", s) != 1) {
        return 0;
    }
    int seen[256] = {0}; 
    int found = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char val = s[i];
        if (seen[val] == 1) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
        seen[val] = 1;
    }
    if (!found) {
        printf("-1\n");
    }
    return 0;
}
