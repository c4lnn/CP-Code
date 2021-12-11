#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        if (a[i] == x) {
            return cout << i << '\n', 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}