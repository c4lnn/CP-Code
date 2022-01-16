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
        LL a, s, b = 0, power = 1;
        cin >> a >> s;
        bool f = false;
        while (s) {
            int x = a % 10, y = s % 10;
            a /= 10, s /= 10;
            if (x <= y) {
                b += (y - x) * power;
            } else {
                y += s % 10 * 10;
                s /= 10;
                if (x <= y && y - x <= 9) {
                    b += (y - x) * power;
                } else {
                    cout << -1 << '\n';
                    f = true;
                    break;
                }
            }
            power *= 10;
        }
        if (!f) {
            cout << (!a ? b : -1) << '\n';
        }
    }
    return 0;
}