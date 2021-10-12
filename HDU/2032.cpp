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
int a[35][35];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << a[i][j] << " \n"[j == i];
            }
        }
        cout << '\n';
    }
    return 0;
}