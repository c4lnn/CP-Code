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
const int N = 10;
int n, m, a[N];
bool f1[N][N], f2[N][N];
bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!f1[i][j]) {
                continue;
            }
            if (!f2[a[i]][a[j]]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        f1[a][b] = f1[b][a] = true;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        f2[a][b] = f2[b][a] = true;
    }
    do {
        if (check()) {
            return cout << "Yes" << '\n', 0;
        }
    } while(next_permutation(a + 1, a + 1 + n));
    cout << "No" << '\n';
    return 0;
}