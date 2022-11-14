class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), ret = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> nxt(n, n);

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;
                if (l == r) {
                    dp[l][r] = 1;
                } else if (s[l] == s[r]) {
                    if (len == 2) {
                        dp[l][r] = 1;
                    } else {
                        dp[l][r] |= dp[l + 1][r - 1];
                    }
                }
            }

        }

        for (int i = 0; i < n; i++) {
            for (int j = i + k - 1; j < n; j++) {
                if (dp[i][j]) {
                    nxt[i] = j;
                    break;
                }
            }
        }
        for (int i = n - 1, t = n - 1; ~i ;i--) {
            if (nxt[i] <= t) {
                ++ret;
                t = i - 1;
            }
        }
        return ret;
    }
};