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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int t = n % m, pre = 0;
    while (k--) {
        int l = pre + 1, r = pre;
        for (int i = 1; i <= t; i++) {
            cout << n / m + 1 << ' ';
            for (int j = 1; j <= n / m + 1; j++) {
                cout << ++r << " \n"[j == n / m + 1];
                if (r == n) {
                    r = 0;
                }
            }
            pre = r;
        }
        int x = r;
        for (int i = 1; i <= m - t; i++) {
            cout << n / m << ' ';
            for (int j = 1; j <= n / m; j++) {
                if (x == n) {
                    x = 0;
                }
                cout << ++x << " \n"[j == n / m];
            }
        }
    }
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