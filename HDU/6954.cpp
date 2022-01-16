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
const int N = 1e7 + 5;
int mn[N];
vector<int> p;
LL res[N];
void prime_seive(int n) {
    for (int i = 2; i <= n; i++) {
        if (!mn[i]) {
            mn[i] = i,
            p.PB(i);
        }
        for (auto x : p) {
            if (x > mn[i] || x * i > n) {
                break;
            }
            mn[x * i] = x;
        }
    }
    for (int i = 3; i <= n; i++) {
        res[i] = res[i - 1] + i * (mn[i] == i ? 2 : 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prime_seive(1e7);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << res[n] << '\n';
    }
    return 0;
}