#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(64));
        for (int i = 0; i < n; i++) {
            dp[i][a[i]] = 1;
            if (i == 0) continue;
            for (int j = 0; j < 64; j++) {
                dp[i][a[i] & j] = (dp[i][a[i] & j] + dp[i - 1][j]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }

        int res = 0;
        for (int i = 0; i < 64; i++) {
            if (__builtin_popcount(i) == k) {
                res = (res + dp[n - 1][i]) % MOD;
            }
        }
        std::cout << res << '\n';

    }
    return 0;
}