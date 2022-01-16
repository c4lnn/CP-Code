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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int w, h;
        cin >> w >> h;
        int k;
        LL mxu = 0, mxd = 0, mxl = 0, mxr = 0, mnu = 1e6, mnd = 1e6, mnl = 1e6, mnr = 1e6;
        cin >> k;
        for (int i = 0; i < k; i++) {
            LL x;
            cin >> x;
            mxd = max(mxd, x);
            mnd = min(mnd, x);
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            LL x;
            cin >> x;
            mxu = max(mxu, x);
            mnu = min(mnu, x);
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            LL x;
            cin >> x;
            mxl = max(mxl, x);
            mnl = min(mnl, x);
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            LL x;
            cin >> x;
            mxr = max(mxr, x);
            mnr = min(mnr, x);
        }
        cout << max({(mxd - mnd) * h, (mxu - mnu) * h, (mxl - mnl) * w, (mxr - mnr) * w}) << '\n';
    }
    return 0;
}