class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(2e5 + 1);
        dp[0] = 1;
        for (int i = 0; i <= high; i++) {
            dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
            dp[i + one] = (dp[i + one] + dp[i]) % MOD;
        }
        for (int i = 1; i <= high; i++) {
            dp[i] = (dp[i - 1] + dp[i]) % MOD;
        }
        return ((dp[high] - dp[low - 1]) % MOD + MOD) % MOD;
    }
};