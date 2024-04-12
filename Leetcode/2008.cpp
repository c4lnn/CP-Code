class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < rides.size(); i++) {
            g[rides[i][1]].push_back(i);
        }
        std::vector<long long> dp(n + 1);
        for (int v = 1; v <= n; v++){
            for (int idx : g[v]) {
                int u = rides[idx][0];
                int w = rides[idx][2];
                dp[v] = std::max(dp[v], dp[u] + v - u + w);
            }
            dp[v] = std::max(dp[v - 1], dp[v]);
        }
        return dp[n];
    }
};