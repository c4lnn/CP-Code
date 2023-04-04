class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> a(k);
        vector<int> cnt(1001);
        for (auto  x : nums) ++cnt[x];
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i]) a[i % k].push_back(i);
        }

        int ret = 1;
        for (int i = 0; i < k; i++) {
            if (a[i].size() == 0) continue;
            vector<vector<int>> dp(a[i].size(), vector<int>(2));
            for (int j = 0; j < a[i].size(); j++) {
                if (j == 0) {
                    dp[j][0] = 1;
                    dp[j][1] = (1 << cnt[a[i][j]]) - 1;
                } else {
                    dp[j][0] = dp[j - 1][0] + dp[j - 1][1];
                    if (a[i][j] - a[i][j - 1] == k) {
                        dp[j][1] = dp[j - 1][0] * ((1 << cnt[a[i][j]]) - 1);
                    } else {
                        dp[j][1] = dp[j - 1][0] + dp[j - 1][1] * ((1 << cnt[a[i][j]]) - 1);
                    }
                }
            }
            ret *= (dp.back()[0] + dp.back()[1]);
        }
        return ret - 1;
    }
};