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
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        int t1 = log10(x1), t2 = log10(x2);
        if (t1 + p1 < t2 + p2) {
            cout << '<' << '\n';
        }
        else if (t1 + p1 > t2 + p2) {
            cout << '>' << '\n';
        }
        else {
            while (t1 < t2) {
                ++t1;
                x1 *= 10;
            }
            while (t1 > t2) {
                ++t2;
                x2 *= 10;
            }
            if (x1 < x2) {
                cout << '<' << '\n';
            }
            else if (x1 == x2) {
                cout << '=' << '\n';
            }
            else {
                cout << '>' << '\n';
            }
        }
    }
    return 0;
}