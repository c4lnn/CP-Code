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
const string S = "nunhehheha";
const LL MOD = 998244353;
const int N = 1e5 + 5;
LL dp[N][20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if(s[0] == 'n') dp[0][0] = 1;
        else dp[0][0] = 0;
        for (int i = 1; i < SZ(s); i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i] != S[j]) continue;
                if (j == 0) dp[i][j] = (dp[i][j] + 1) % MOD;
                else if (j == 9) dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i-1][j]) % MOD;
                else dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
        }
        cout << dp[SZ(s) - 1][9] << '\n';
    }
    return 0;
}