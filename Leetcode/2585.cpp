class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& a) {
        int n = a.size();
        const int MOD  = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(target + 1));
        for (int i = 0; i <= a[0][0]; i++) {
            if (i * a[0][1] > target) { break; }
            dp[0][i * a[0][1]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= a[i][0]; k++) {
                    if (j - k * a[i][1] < 0) { break; }
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k * a[i][1]]) % MOD;
                }
            }
        }
        return dp[n - 1][target];
    }
};