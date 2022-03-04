#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int n;
long long s;
bool check(int mid) {
    for (int i = 1; i + 2 * mid - 1 <= n; i++) {
        if (a[i + mid - 1] - a[i - 1] <= s && a[i + 2 * mid - 1] - a[i + mid - 1] <= s) {
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> s;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int l = 0, r = n / 2;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l * 2 << '\n';
    return 0;
}