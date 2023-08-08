class Solution {
public:
    const int MOD = 1e9 + 7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<int> dp(n, 0x3f3f3f3f);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 1] - dp[nextVisit[i - 1]] + 2) % MOD + MOD) % MOD;
        }
        return (dp[n - 1] - 1 + MOD) % MOD;
    }
};