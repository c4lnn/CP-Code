#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    long long res = 0;
    m = min(m, n);
    for (int i = 0; i < m; i++) {
        res += a[i];
    }
    cout << res << '\n';
    return 0;
}