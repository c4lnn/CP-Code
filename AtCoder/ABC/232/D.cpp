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
int mx[N][N];
string s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int res = 0;
    mx[0][0] = 1;
    for (int i  = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                continue;
            }
            if (i - 1 >= 0 && mx[i - 1][j] >= 1) {
                mx[i][j] = max(mx[i][j], mx[i - 1][j] + 1);
            }
            if (j - 1 >= 0 && mx[i][j - 1] >= 1) {
                mx[i][j] = max(mx[i][j], mx[i][j - 1] + 1);
            }
            res = max(res, mx[i][j]);
        }
    }
    cout << res << '\n';
    return 0;
}