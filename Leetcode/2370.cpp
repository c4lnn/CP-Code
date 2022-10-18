class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 1), pre(26, -1);
        for (int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            for (int j = max(0, t - k); j <= min(25, t + k); j ++) {
                if (pre[j] != -1) {
                    dp[i] = max(dp[i], dp[pre[j]] + 1);
                }
            }
            pre[t] = i;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};