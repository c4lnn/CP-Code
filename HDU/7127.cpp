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
        DB a, b, c;
        cin >> a >> b >> c;
        DB x0, x1, y0, y1, y2;
        cin >> x0 >> x1 >> y0 >> y1 >> y2;
        DB delta = b * b - 4 * a * (c - y0);
        if (delta <= 0) {
            cout << "No" << '\n';
        }
        else {
            DB l = (-b + sqrt(delta)) / (2 * a), r = (-b - sqrt(delta)) / (2 * a);
            if (l >= x0) {
                cout << "No" << '\n';
            }
            else {
                DB  y = a * x1 * x1 + b * x1 + c;
                if (r > x0 && r < x1) {
                    cout << "Yes" << '\n';
                }
                else if (y > y0 && y <= y2 && r > x1 && r < (x1 + x1 - x0))
                    cout << "Yes" << '\n';
                else {
                   cout << "No" << '\n';
                }
            }
        }
    }
    return 0;
}