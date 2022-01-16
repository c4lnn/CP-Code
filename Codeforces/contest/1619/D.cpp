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
int m, n;
bool check(vector<VI> &p, int mid) {
    vector<bool> f(m + 1);
    bool ok = false;
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
        bool fj = false;
        for (int i = 1; i <= m; i++) {
            if (p[i][j] >= mid) {
                if (!fj) {
                    fj = true;
                    ++cnt;
                }
                if (f[i]) {
                    ok = true;
                } else {
                    f[i] = true;
                }
            }
        }
    }
    if (cnt < n || !ok) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        vector<VI> p(m + 1, VI(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> p[i][j];
            }
        }
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(p, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}