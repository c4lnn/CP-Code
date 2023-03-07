class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        vector<int> fa(n, -1), sum(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        function<void(int)> dfs1 = [&](int u) -> void {
            for (auto v : g[u]) {
                if (v == fa[u]) {
                    continue;
                }
                fa[v] = u;
                dfs1(v);
            }
        };
        dfs1(0);
        for (const auto& x : guesses) {
            int u = x[0], v = x[1];
            if (u == fa[v]) {
                sum[v]--;
                sum[0]++;
            } else if (v == fa[u]) {
                sum[u]++;
            }
        }
        function<void(int)> dfs2 = [&](int u) -> void {
            for (auto v : g[u]) {
                if (v == fa[u]) {
                    continue;
                }
                sum[v] += sum[u];
                dfs2(v);
            }

        };
        dfs2(0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (sum[i] >= k) {
                ++ret;
            }
        }
        return ret;
    }
};