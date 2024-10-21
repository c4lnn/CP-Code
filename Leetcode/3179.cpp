class Solution {
public:
    int MOD = 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n));
        std::fill(dp[0].begin(), dp[0].end(), 1);
        for (int i = 1; i <= k; i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        return dp[k][n - 1];
    }
};