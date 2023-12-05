#include <bits/stdc++.h>
void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1));
    dp[0][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = s[i - 1] == s[i - 2] ? 1 : dp[0][i - 1] + 1;
    }
    dp[1][n - 1] = 1;
    for (int i = n - 2; ~i; i--) {
        dp[1][i] = s[i] == s[i + 1] ? 1 : dp[1][i + 1] + 1;
    }
    for (int i = 0; i <= n; i++) {
        int sum = 0;
        int t = 0;
        if (i > 0 && s[i - 1] == 'L') {
            sum += dp[0][i] + 1;
            t++;
        }

        if (i < n && s[i] == 'R') {
            sum += dp[1][i] + 1;
            t++;
        }
        std::cout << sum - t + 1 << " \n"[i == n];
    }
}
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}