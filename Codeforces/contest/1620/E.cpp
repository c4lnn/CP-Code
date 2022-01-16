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
const int N = 5e5 + 5;
int o[N], x[N], y[N], to[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> o[i] >> x[i];
        if (o[i] == 2) {
            cin >> y[i];
        }
    }
    VI res;
    for (int i = 1; i <= 5e5; i++) {
        to[i] = i;
    }
    for (int i = q; i; i--) {
        if (o[i] == 1) {
            res.PB(to[x[i]]);
        } else {
            to[x[i]] = to[y[i]];
        }
    }
    for (int i = SZ(res) - 1; ~i; i--) {
        cout << res[i] << " \n"[!i];
    }
    return 0;
}