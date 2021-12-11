#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int main() {
    int n;
    cin >> n;
    a[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            cout << a[i][j] << " \n"[j == i];
        }
    }
    return 0;
}