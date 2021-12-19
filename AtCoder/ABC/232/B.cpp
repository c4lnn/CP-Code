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
    string a, b;
    cin >> a >> b;
    int t = ((a[0] - b[0]) % 26 + 26) % 26;
    for (int i = 1; i < SZ(a); i++) {
        if (((a[i] - b[i])% 26 + + 26) % 26 != t) {
            return cout << "No" << '\n', 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}