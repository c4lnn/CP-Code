#include <bits/stdc++.h>
void solve() {
    int n, k;
    long long x;
    std::cin >> n >> k >> x;
    x--;
    std::string s, t;
    std::cin >> s;
    int cnt = 0;
    for (int i = n - 1; ~i; i--) {
        if (s[i] == 'a') {
            t += std::string(x % (cnt * k + 1), 'b');
            x /= cnt * k + 1;
            t += 'a';
            cnt = 0;
        } else {
            cnt++;
        }
    }
    t += std::string(x % (cnt * k + 1), 'b');
    x /= cnt * k + 1;
    std::reverse(t.begin(), t.end());
    std::cout << t << '\n';
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}