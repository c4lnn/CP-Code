const int N = 1e5;
vector<bool> vis;
vector<int> fa;
vector<vector<int>> p;
class Solution {
public:
    void init() {
        vis.resize(N + 1);
        p.resize(N + 1);
        for (int i = 2; i <= N; i++) {
            if (vis[i] == true) continue;
            for (int j = i; j <= N; j += i) {
                p[j].push_back(i);
                vis[j] = true;
            }
        }
        fa.resize(N);
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        fa[x] = y;
    }
    bool canTraverseAllPairs(vector<int>& a) {
        if (p.size() == 0) init();
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++) {
            int x = a[i];
            fa[i] = i;
            for(auto prime : p[x]) {
                if (!mp.count(prime)) {
                    mp[prime] = i;
                } else {
                    merge(mp[prime], i);
                }
            }
        }
        for (int i = 1; i < a.size(); i++) {
            if (find(i) != find(i - 1)) return false;
        }
        return true;
    }
};