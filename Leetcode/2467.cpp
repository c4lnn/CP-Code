class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& e, int bob, vector<int>& a) {
        int n = e.size() + 1;
        vector<vector<int>> g(n);
        vector<int> fa(n, -1), val(n), step(n, INT_MAX);
        int res = INT_MIN;

        for (const auto& ee : e) {
            int u = ee[0], v = ee[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        std::function<void(int)> dfs1 = [&](int u) -> void {
            for (auto v : g[u]) {
                if (v != fa[u]) {
                    fa[v] = u;
                    dfs1(v);
                }
            }
        };

        dfs1(0);

        for (int i = 0; bob != -1; bob = fa[bob], i++) {
            step[bob] = i;
        }

        std::function<void(int, int)> dfs2 = [&](int u, int cnt) -> void {
            if (u == 0) {
                val[u] = a[u];
            } else if (step[u] < cnt) {
                val[u] = val[fa[u]];
            } else if (step[u] == cnt) {
                val[u] = val[fa[u]] + a[u] / 2;
            } else {
                val[u] = val[fa[u]] + a[u];
            }

            if (u != 0 && g[u].size() == 1) {
                res = max(res, val[u]);
            }

            for (auto v : g[u]) {
                if (v != fa[u]) {
                    dfs2(v, cnt + 1);
                }
            }
        };

        dfs2(0, 0);

        return res;
    }
};