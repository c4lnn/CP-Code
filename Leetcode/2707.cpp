class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n);
        for (int r = 0; r < n; r++) {
            if (r != 0) dp[r] = dp[r - 1];
            for (int l = 0; l <= r; l++) {
                string t = s.substr(l, r - l + 1);
                for (auto& str : dictionary) {
                    if (t == str) {
                        dp[r] = max(dp[r], (l == 0 ? 0 : dp[l - 1]) + r - l + 1);
                    }
                }
            }
        }
        return n - dp[n - 1];
    }
};