// #include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
// using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N = 1e5 + 5;
bool vis[N], st[N];
class Solution {
public:
    VPII c[N];
    vector<int> findAllPeople(int n, vector<vector<int>>& a, int s) {
        VI ret, b;
        memset(vis, false, sizeof vis);
        memset(st, false, sizeof st);
        st[0] = st[s] = true;
        for (auto x : a) {
            b.PB(x[2]);
        }
        sort(ALL(b));
        b.resize(unique(ALL(b)) - b.begin());
        for (auto x : a) {
            c[lower_bound(ALL(b), x[2]) - b.begin()].EB(x[0], x[1]);
        }
        for (int i = 0; i < SZ(b); i++) {
            queue<int> q;
            unordered_set<int> t;
            unordered_map<int, VI> g;
            for (auto x : c[i]) {
                t.insert(x.FI);
                t.insert(x.SE);
                g[x.FI].PB(x.SE);
                g[x.SE].PB(x.FI);
            }
            for (auto x : t) {
                if (st[x]) {
                    vis[x] = true;
                    q.push(x);
                } else {
                    vis[x] = false;
                }
            }
            while (SZ(q)) {
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
                ret.PB(i);
            }
        }
        return ret;
    }
};
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution::;
//     return 0;
// }