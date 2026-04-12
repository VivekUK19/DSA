#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int m, n;
    int table[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++) table[i] = -1; // -1 represents empty

    scanf("%d %d", &m, &n);

    char op[10];
    int key;
    while(n--) {
        scanf("%s %d", op, &key);
        if(strcmp(op, "INSERT") == 0) {
            for(int i=0; i<m; i++) {
                int pos = (key % m + i*i) % m;
                if(table[pos] == -1) {
                    table[pos] = key;
                    break;
                }
            }
        } else if(strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for(int i=0; i<m; i++) {
                int pos = (key % m + i*i) % m;
                if(table[pos] == key) {
                    found = 1; break;
                }
                if(table[pos] == -1) break;
            }
            printf("%s\n", found ? "FOUND" : "NOT FOUND");
        }
    }
    return 0;
}
