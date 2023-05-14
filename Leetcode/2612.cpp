class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ret(n);
        set<int> s[2];
        for(auto x :banned) ret[x] = -1;
        for (int i = 0; i < n; i++) {
            if (ret[i] != -1 && i != p) {
                s[i % 2].insert(i);
            }
        }
        for (int i = 0; i < n; i++) ret[i] = -1;
        queue<int> q;
        q.push(p);
        ret[p] = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            int t = (u - k + 1) & 1;
            int l = max(u - k + 1, k - 1 - u);
            int r = min(u + k - 1, 2 * n - k - u);
            for(auto it = s[t].lower_bound(l); it != s[t].end() && *it <= r; it = s[t].erase(it)) {
                ret[*it] = ret[u] + 1;
                q.push(*it);
            }
        }
        return ret;
    }
};