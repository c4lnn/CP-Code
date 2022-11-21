class Solution {
public:
    int longestCycle(vector<int>& e) {
        vector<int> in(e.size(), -1);
        vector<bool> vis(e.size());
        stack<int> stk;
        int ret = -1;
        function<void(int)> dfs = [&](int u) -> void {
            if (in[u] != -1) {
                ret = max(ret, int(stk.size()) - in[u]);
                return;
            }
            if (vis[u]) {
                return;
            }
            in[u] = stk.size();
            stk.push(u);
            vis[u] = true;
            if (e[u] != -1) {
                dfs(e[u]);
            }
            stk.pop();
            in[u] = -1;
        };
        for (int i = 0; i < e.size(); i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        return ret;
    }
};