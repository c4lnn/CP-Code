#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mx = 0xc0c0c0c0, mn = 0x3f3f3f3f, sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
        sum += x;
    }
    cout << mx << '\n' << mn << '\n' << sum << '\n';
    return 0;
}