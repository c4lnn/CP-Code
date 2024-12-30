class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumOfPowers(vector<int>& a, int m) {
        int n = a.size();
        std::sort(a.begin(), a.end());
        std::vector<int> diff;
        std::vector<std::vector<std::unordered_map<int, int>>> dp(n, std::vector<std::unordered_map<int, int>>(m + 1));
        for (int i = 0; i < n; i++) {
            dp[i][1][INT_MAX] = 1;
            for (int j = 0; j < i; j++) {
                for (int k = 2; k <= m; k++) {
                    int diff = a[i] - a[j];
                    for (const auto& [min, cnt] : dp[j][k - 1]) {
                        dp[i][k][std::min(min, diff)] = (dp[i][k][std::min(min, diff)] + dp[j][k - 1][min]) % MOD;
                    }
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (const auto& [min, cnt] : dp[i][m]) {
                ret = (ret + 1ll * min * cnt % MOD) % MOD;
            }
        }
        return ret;
    }
};