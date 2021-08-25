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
const int N=1e6+5;
LL f[N],g[N],h[N];
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
    for(int i=3;i<=1000000;i++) {
        if(i&1) f[i]=(f[(i-1)/2]*2+1)%MOD;
        else f[i]=(f[i/2-1]+f[i/2]+1)%MOD;
    }
    for(int i=2;i<=1000000;i++) g[i]=(f[i-1]+1)%MOD;
    for(int i=2;i<=1000000;i++) g[i]=(g[i]+g[i-1])%MOD;
    for(int i=1;i<=1000000;i++) h[i]=(g[i-1]*2+i)%MOD*qpow(i,MOD-2)%MOD;
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        cout<<h[n]<<'\n';
    }
    return 0;
}