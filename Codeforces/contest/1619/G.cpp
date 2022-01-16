#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N = 2e5 + 5;
int x[N], y[N], t[N], fa[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy =find(y);
    if (fx == fy) {
        return;
    }
    fa[fx] = fy;
    t[fy] = min(t[fy], t[fx]);
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> t[i];
        fa[i] = i;
    }
    VI a(n);
    iota(ALL(a), 0);
    sort(ALL(a), [&](int i, int j) {
        return x[i] != x[j] ? x[i] < x[j] : y[i] < y[j];
    });
    for (int i = 1; i < n; i++) {
        if (x[a[i]] == x[a[i - 1]] && y[a[i]] - y[a[i - 1]] <= k) {
            merge(a[i], a[i - 1]);
        }
    }
    sort(ALL(a), [&](int i, int j) {
        return y[i] != y[j] ? y[i] < y[j] : x[i] < x[j];
    });
    for (int i = 1; i < n; i++) {
        if (y[a[i]] == y[a[i - 1]] && x[a[i]] - x[a[i - 1]] <= k) {
            merge(a[i], a[i - 1]);
        }
    }
    VI v;
    for (int i = 0; i < n; i++) {
        if (fa[i] == i) {
            v.PB(t[i]);
        }
    }
    sort(ALL(v), greater<int>());
    int res = -1;
    for (auto x : v) {
        if (x > res) {
            ++res;
        }
    }
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}