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
const int N = 105;
LL a[N];
int n;
LL check(LL mid) {
    LL ret = 0, nxt;
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            nxt = min(nxt, a[i] - 1);
            ret += nxt - a[i - 1] + 1;
        }
        nxt = a[i] + mid - 1;
    }
    return ret + nxt - a[n] + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        LL h;
        cin >> n >> h;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        LL l = 1, r = h;
        while (l < r) {
            LL mid = l + r >> 1;
            if (check(mid) >= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}