class Solution {
public:
    bool validPartition(vector<int>& a) {
        int n = a.size();
        vector<vector<bool>> dp(n, vector<bool>(8));
        dp[0][0] = dp[0][2] = dp[0][5] = true;
        for (int i = 1; i < n; i++) {
            if (dp[i - 1][1] || dp[i - 1][4] || dp[i - 1][7]) { dp[i][0] = dp[i][2] = dp[i][5] = true; }
            if (dp[i - 1][0] && a[i] == a[i - 1]) { dp[i][1] = true; }
            if (dp[i - 1][2] && a[i] == a[i - 1]) { dp[i][3] = true; }
            if (dp[i - 1][3] && a[i] == a[i - 1]) { dp[i][4] = true; }
            if (dp[i - 1][5] && a[i] == a[i - 1] + 1) { dp[i][6] = true; }
            if (dp[i - 1][6] && a[i] == a[i - 1] + 1) { dp[i][7] = true; }
        }
        return dp[n - 1][1] | dp[n - 1][4] || dp[n - 1][7];
    }
};