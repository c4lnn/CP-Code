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
const LL MOD = 998244353;
const int N = 1e6 + 5;
LL fac[N], invfac[N], dp1[N][2], dp2[N][2];
LL qpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if(b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; ~i; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(1e6);
    int n, m, k, x1, y1, x2, y2;
    cin >> n >> m >> k >> x1 >> y1 >> x2 >> y2;
    dp1[0][0] = (x1 == x2);
    dp1[0][1] = (x1 != x2);
    for (int i = 1; i <= k; i++) {
        dp1[i][0] = dp1[i - 1][1];
        dp1[i][1] = (dp1[i - 1][1] * (n - 2) % MOD + dp1[i - 1][0] * (n - 1)) % MOD;
    }
    dp2[0][0] = (y1 == y2);
    dp2[0][1] = (y1 != y2);
    for (int i = 1; i <= k; i++) {
        dp2[i][0] = dp2[i - 1][1];
        dp2[i][1] = (dp2[i - 1][1] * (m - 2) % MOD + dp2[i - 1][0] * (m - 1)) % MOD;
    }
    LL res = 0;
    for (int i = 0; i <= k; i++) {
        res = (res + dp1[i][0] * dp2[k - i][0] % MOD * fac[k] % MOD * invfac[i] % MOD * invfac[k - i]  % MOD) % MOD;
    }
    cout << res << '\n';
    return 0;
}