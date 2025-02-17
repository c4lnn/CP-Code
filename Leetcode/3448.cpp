class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(10, std::vector<int>(10)));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 9; j++) {
                dp[i][j][a[i] % j] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 0; k < j; k++) {
                    int d = k * 10 + a[i];
                    dp[i][j][d % j] += dp[i - 1][j][k];
                }
            }
        }
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                ret += dp[i][a[i]][0];
            }
        }
        return ret;
    }
};