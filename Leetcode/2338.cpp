class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        std::vector<std::vector<long long>> dp(21, std::vector<long long>(n + 1));
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MOD;
            }
        }
        int ret = 0;
        for (int i = 1; i <= maxValue; i++) {
            int d = i;
            long long sum = 1;
            for (int j= 2; j * j <= d; j++) {
                int cnt = 0;
                if (d % j == 0) {
                    while (d % j == 0) {
                        ++cnt;
                        d /= j;
                    }
                    sum = sum * dp[cnt][n] % MOD;
                }
            }
            if (d > 1) {
                sum = sum * n % MOD;
            }
            ret = (ret + sum) % MOD;
        }
        return ret;
    }
};