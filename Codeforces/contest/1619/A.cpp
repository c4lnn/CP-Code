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
        string s;
        cin >> s;
        if (SZ(s) & 1) {
            cout << "NO" << '\n';
        } else {
            bool f = false;
            for (int i = 0; i < SZ(s) / 2; i++) {
                if (s[i] != s[i + SZ(s) / 2]) {
                    cout << "NO" << '\n';
                    f = true;
                    break;
                }
            }
            if (!f) {
                cout << "YES" << '\n';
            }
        }
    }
    return 0;
}