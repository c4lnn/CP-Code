class Solution {
public:
    const int N = 1e5 + 5;
    vector<int> findAllPeople(int n, vector<vector<int>>& a, int s) {
        vector<vector<pair<int, int>>> c(N);
        vector<bool> vis(N), st(N);
        vector<int> ret, b;
        st[0] = st[s] = true;
        for (auto x : a) {
            b.push_back(x[2]);
        }
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (auto x : a) {
            c[lower_bound(b.begin(), b.end(), x[2]) - b.begin()].emplace_back(x[0], x[1]);
        }
        for (int i = 0; i < b.size(); i++) {
            queue<int> q;
            unordered_set<int> t;
            unordered_map<int, vector<int>> g;
            for (auto x : c[i]) {
                t.insert(x.first);
                t.insert(x.second);
                g[x.first].push_back(x.second);
                g[x.second].push_back(x.first);
            }
            for (auto x : t) {
                if (st[x]) {
                    vis[x] = true;
                    q.push(x);
                } else {
                    vis[x] = false;
                }
            }
            while (q.size()) {
                int u = q.front();
                q.pop();
                st[u] = true;
                for (auto v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (st[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};