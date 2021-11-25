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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=1e6+5;
const LL MOD=998244353;
int cnt[N];
LL fac[N],invfac[N],f[N],sum[N];
LL binom(int n,int m) {
    return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}
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
    int n;cin>>n;
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    invfac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        ++cnt[x];
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
    f[0]=1;
    for(int i=1;i<=n;i++) {
        if(cnt[i]) f[i]=f[i-1]*fac[cnt[i]]%MOD*binom(cnt[i]/2+sum[i-1],cnt[i]/2)%MOD;
        else f[i]=f[i-1];
    }
    cout<<f[n]<<'\n';
    return 0;
}