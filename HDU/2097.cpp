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
    while (cin >> n) {
        if (!n) break;
        int t = n, sum10 = 0, sum12 = 0, sum16 = 0;
        while (t) {
            sum10 += t % 10;
            t /= 10;
        }
        t = n;
        while (t) {
            sum12 += t % 12;
            t /= 12;
        }
        t = n;
        while (t) {
            sum16 += t % 16;
            t /= 16;
        }
        if (sum10 == sum12 && sum10 == sum16) cout << n << " is a Sky Number.\n";
        else cout << n << " is not a Sky Number.\n";
    }
    return 0;
}