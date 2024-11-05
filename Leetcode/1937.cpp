class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        std::vector<std::vector<long long>> dp(n, std::vector<long long>(m));
        std::vector<long long> pre_max(m), suf_max(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = a[i][j];
                if (i) {
                    dp[i][j] += std::max(-j + pre_max[j], j + suf_max[j]);
                }
            }
            pre_max[0] = dp[i][0];
            for (int j = 1; j < m; j++) {
                pre_max[j] = std::max(pre_max[j - 1], dp[i][j] + j);
            }
            suf_max[m - 1] = dp[i][m - 1] - m + 1;
            for (int j = m - 2; ~j; j--) {
                suf_max[j] = std::max(suf_max[j + 1], dp[i][j] - j);
            }
        }
        long long ret = 0;
        for (int i = 0; i < m; i++) {
            ret = std::max(ret, dp[n - 1][i]);
        }
        return ret;
    }
};