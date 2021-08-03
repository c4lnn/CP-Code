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
const LL MOD=1e9+7;
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
    int T;cin>>T;
    while(T--) {
        LL n;cin>>n;
        n%=MOD;
        LL res=0;
        res=(res+n*(n+1)%MOD*n%MOD*(n+1)%MOD*(2*n+1)%MOD*qpow(12,MOD-2)%MOD)%MOD;
        res=(res+((n*(n+1)%MOD*qpow(2,MOD-2)%MOD-1+MOD)%MOD)*((n*(n+1)%MOD*qpow(2,MOD-2)%MOD-1+MOD)%MOD)%MOD)%MOD;
        res=(res+((n*(n+1)%MOD*(2*n+1)%MOD*qpow(6,MOD-2)%MOD-1+MOD)%MOD)*((n*(n+1)%MOD*qpow(2,MOD-2)%MOD-1+MOD)%MOD)%MOD)%MOD;
        cout<<res<<'\n';
        res=n*(n+1)%MOD*n%MOD*(n+1)%MOD*(2*n+1)%MOD*n%MOD*n%MOD*qpow(12,MOD-2)%MOD;
        cout<<res<<'\n';
    }
    return 0;
}