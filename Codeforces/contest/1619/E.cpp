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
        int n;
        cin >> n;
        VI cnt(n + 1), sum(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x <= n) {
                ++cnt[x];
            }
        }
        sum[0] = cnt[0];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + cnt[i];
        }
        LL res = 0;
        bool f = false;
        stack<int> stk;
        for (int i = 0; i <= n; i++) {
            if (i && sum[i - 1] < i || f) {
                f = true;
                cout << -1 << " \n"[i == n];
            } else {
                cout << res + cnt[i] << " \n"[i == n];
                if (cnt[i] == 0) {
                    if (SZ(stk)) {
                        res += i - stk.top();
                        stk.pop();
                    } else {
                        f = true;
                    }
                } else {
                    for (int j = 2; j <= cnt[i]; j++) {
                        stk.push(i);
                    }
                }
            }
        }
    }
    return 0;
}