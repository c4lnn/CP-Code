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
        VI a;
        for (int i = 1; i * i <= 1e9; i++) {
            a.PB(i * i);
        }
        for (int i = 1; i * i * i <= 1e9; i++) {
            a.PB(i * i * i);
        }
        sort(ALL(a));
        a.resize(unique(ALL(a)) - a.begin());
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            cout << upper_bound(ALL(a), n) - a.begin() << '\n';
        }
        return 0;
    }