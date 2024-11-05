class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        int cnt = 0;
        std::vector<std::vector<int>> trie(19 * n, std::vector<int>(2));
        std::vector<int> tot(19 * n);
        auto ins = [&](int val, int o) -> void {
            int u = 0;
            for (int i = 18; ~i; i--) {
                int bit = (val >> i) & 1;
                if (!trie[u][bit]) {
                    trie[u][bit] = ++cnt;
                }
                u = trie[u][bit];
                tot[u] += o;
            }
        };
        auto qry = [&](int val) -> int {
            int u = 0, ret = 0;;
            for (int i = 18; ~i; i--) {
                int bit = (val >> i) & 1;
                if (trie[u][!bit] && tot[trie[u][!bit]]) {
                    ret |= 1 << i;
                    u = trie[u][!bit];
                } else {
                    u = trie[u][bit];
                }
            }
            return ret;
        };
        std::vector<int> ret(queries.size());
        std::vector<std::vector<std::pair<int, int>>> q(n);
        for (int i = 0; i < queries.size(); i++) {
            q[queries[i][0]].emplace_back(i, queries[i][1]);
        }
        int root = 0;
        std::vector<std::vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                root = i;
            } else {
                g[parents[i]].push_back(i);
            }
        }
        auto dfs = [&](int u, int fa, auto&& dfs) -> void {
            ins(u, 1);
            for (auto [idx, val] : q[u]) {
                ret[idx] = qry(val);
            }
            for (auto v : g[u]) {
                if (v == fa) {
                    continue;
                }
                dfs(v, u, dfs);
            }
            ins(u, -1);
        };
        dfs(root, -1, dfs);
        return ret;
    }
};