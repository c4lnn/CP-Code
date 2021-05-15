#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n) {
        LL res=0;
        VI a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(ALL(a));
        a.resize(unique(ALL(a))-a.begin());
        for(auto x:a) {
            if(__builtin_popcount(x)&1) res^=2ll*x;
            else res^=2ll*x+1;
        }
        cout<<(res?"No":"Yes")<<'\n';
    }
    return 0;
}