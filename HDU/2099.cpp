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
    int a, b;
    while (cin >> a >> b) {
        if(!a && !b) break;
        VI res;
        for (int i = 0; i < 100; i++) if ((a * 100 + i) % b == 0) {
            res.PB(i);
        }
        for (int i = 0; i < SZ(res); i++) {
            printf("%02d%c", res[i], " \n"[i == SZ(res) - 1]);
        }
    }
    return 0;
}