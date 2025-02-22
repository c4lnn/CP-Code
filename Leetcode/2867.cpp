class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> g(n + 1);
        for (auto& vec : edges) {
            g[vec[0]].push_back(vec[1]);
            g[vec[1]].push_back(vec[0]);
        }
        std::vector<int> prime(n + 1, 1), size(n + 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (!prime[i]) {
                continue;
            }
            for (int j = i + i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
        std::vector<int> node;
        std::function<void(int, int)> dfs = [&](int u, int fa) -> void {
            node.push_back(u);
            for (auto v : g[u]) {
                if (v == fa || prime[v]) {
                    continue;
                }
                dfs(v, u);
            }
        };
        long long ret = 0;
        for (int u = 1; u <= n; u++) {
            if (!prime[u]) {
                continue;
            }
            long long sum = 0;
            for (auto v : g[u]) {
                if (prime[v]) {
                    continue;
                }
                if (!size[v]) {
                    node.clear();
                    dfs(v, -1);
                    for (auto x : node) {
                        size[x] = node.size();
                    }
                }
                ret += size[v] * (sum + 1);
                sum += size[v];
            }
        }
        return ret;
    }
};