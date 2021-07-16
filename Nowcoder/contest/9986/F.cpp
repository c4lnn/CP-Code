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
const ULL MOD=998244353;
ULL qpow(ULL a,ULL b) {
    ULL ret=1;
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
    ULL n;
    cin>>n;
    n/=4;
    ++n;
    if(n==1) cout<<1<<'\n';
    else {
        ULL t=qpow(2,(n-2)*2+1);
        if(n&1) cout<<t*(t+1)%MOD<<'\n';
        else cout<<t*((t-1+MOD)%MOD)%MOD<<'\n';
    }
    return 0;
}