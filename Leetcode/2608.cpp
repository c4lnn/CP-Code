class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto vec : edges) {
            int u = vec[0], v = vec[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ret = INT_MAX;
        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            vector<int> dep(n), pre(n);
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (v == pre[u]) continue;
                    if (dep[v]) {
                        ret = min(ret, dep[v] + dep[u] + 1);
                    } else {
                        pre[v] = u;
                        dep[v] = dep[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};