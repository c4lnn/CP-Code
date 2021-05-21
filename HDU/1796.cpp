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
    int n,m;
    while(cin>>n>>m) {
        --n;
        vector<LL> a;
        for(int i=0;i<m;i++) {
            int x;cin>>x;
            if(x) a.PB(x);
        }
        m=SZ(a);
        LL res=0;
        for(int i=1;i<1<<m;i++) {
            LL lcm=1;
            int cnt=0;
            for(int j=0;j<m;j++) if(i&(1<<j)) {
                lcm=lcm*a[j]/__gcd(lcm,a[j]);
                ++cnt;
            }
            res+=(cnt&1?1:-1)*(n/lcm);
        }
        cout<<res<<'\n';
    }
    return 0;
}