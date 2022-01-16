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
const int N = 20;
int n, a[N], b[N], popcount[1 << N];
LL x, y, dp[1 << N];
int f(int a, int b) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (a & (1 << i) && i > b) {
            ++ret;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < 1 << n; i++) {
        popcount[i] = popcount[i & (i - 1)] + 1;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + y * f(i, j) + x * abs(a[j] - b[popcount[i] - 1]));
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}