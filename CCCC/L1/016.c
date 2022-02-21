#include <stdio.h>
const int A[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char T[] = "10X98765432";
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0, i;
    for (i = 1; i <= n; i++) {
        char s[20];
        scanf("%s", s);
        int f = 0, z = 0, j;
        for (j = 0; j < 17; j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                z += (s[j] - '0') * A[j];
            } else {
                f = 1;
                break;
            }
        }
        z %= 11;
        if (T[z] != s[17]) {
            f = 1;
        }
        if (f) {
            ++cnt;
            printf("%s\n", s);
        }
    }
    if (!cnt) {
        puts("All passed");
    }
    return 0;
}