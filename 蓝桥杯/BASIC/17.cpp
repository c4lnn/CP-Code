#include <bits/stdc++.h>
using namespace std;
int a[30][30], t[30][30], res[30][30];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            res[i][j] = a[i][j];
        }
    }
    if (!m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (i == j) << " \n"[j == n - 1];
            }
        }
        return 0;
    }
    while (--m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = res[i][j];
                res[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] += t[i][k] * a[k][j];
                }
            }
        }

    }
    for (int i = 0; i < n ;i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}