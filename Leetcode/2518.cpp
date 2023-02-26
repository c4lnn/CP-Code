class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k));
        dp[0][0] = 1;
        if (nums[0] < k) {
            dp[0][nums[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - nums[i]]) % MOD;
                }
            }
        }
        long long sum = 0;
        int ret = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ret = ret * 2 % MOD;
        }
        for (int i = 0; i < k; i++) {
            ret = ((ret - dp[n - 1][i]) % MOD + MOD) % MOD;
            if (sum - i >= k) {
                ret = ((ret - dp[n - 1][i]) % MOD + MOD) % MOD;
            }
        }
        return ret;
    }
};