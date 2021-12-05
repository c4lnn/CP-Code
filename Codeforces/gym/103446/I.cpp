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
LL dp[105][105][6000], a[105], b[105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    memset(dp, 0xc0, sizeof dp);
    dp[0][0][2600] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= 5200; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k + b[i] <= 5200) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k + b[i]] + a[i]);
                }
                if (k - b[i] >= 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - b[i]] + a[i]);
                }
                if (j && k + 2 * b[i] <= 5200) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k + 2 * b[i]] + a[i]);
                }
                if (j && k - 2 * b[i] >= 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 2 * b[i]] + a[i]);
                }
            }
        }
    }
    LL res = 0;
    for (int i = 0; i <= m; i++) {
        res=max(res, dp[n][i][2600]);
    }
    cout << res << '\n';
    return 0;
}