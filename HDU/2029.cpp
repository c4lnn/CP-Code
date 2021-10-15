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
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool f = false;
        for (int i = 0; i <= SZ(s) - 1 - i; i++) if (s[i] != s[SZ(s) - 1 - i]) {
            f = true;
            break;
        }
        cout << (f ? "no" : "yes") << '\n';
    }
    return 0;
}