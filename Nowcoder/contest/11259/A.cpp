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
const LL MOD=4933;
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k,a,l;cin>>n>>m>>k>>a>>l;
    int t=1;
    for(int i=1;i<=k;i++) {
        int x,y,z;cin>>x>>y>>z;
        if(x) t=t*(z-y)%MOD*qpow(z,MOD-2)%MOD;
    }
    cout<<(a+t)%MOD<<'\n';
    return 0;
}