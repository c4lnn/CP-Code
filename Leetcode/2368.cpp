class Solution {
public:
    
    int reachableNodes(int n, vector<vector<int>>& e, vector<int>& r) {
        vector<vector<int>>g(n);
        vector<bool> vis(n);
        for (auto& ee : e) {
            g[ee[0]].push_back(ee[1]);
            g[ee[1]].push_back(ee[0]);
        }
        for (auto x : r) {
            vis[x] = true;
        }
        int ret = 0;
        std::function<void(int)> dfs = [&](int u) -> void {
            ++ret;
            vis[u] = true;
            for (auto v : g[u]) {
                if (!vis[v]) {
                    dfs(v);
                } 
            }
        };
        dfs(0);
        return ret;
    }
};