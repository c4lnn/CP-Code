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
const int N=3e5+5;
LL fac[N],invfac[N],F[N],res[N];
int cnt[N],mn[N],mu[N];
VI p;
void get_mu(int n) {
    mu[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,mu[i]=-1,p.PB(i);
        for(auto x:p) {
            if(x*i>n) break;
            mn[x*i]=x;
            if(i%x==0) {mu[x*i]=0;break;}
            mu[x*i]=-mu[i];
        }
    }
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
void init_invfac(LL n) {
    n=min(n,MOD-1);
    fac[0]=1;
    for(LL i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    invfac[n]=qpow(fac[n],MOD-2);
    for(LL i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
}
LL C(int n,int m) {
    return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_invfac(3e5);
    get_mu(3e5);
    int n,m,k;
    while(cin>>n>>m>>k) {
        for(int i=1;i<=m;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            ++cnt[x];
        }
        for(int i=1;i<=m;i++)
            for(int j=i*2;j<=m;j+=i)
                cnt[i]+=cnt[j];
        for(int i=1;i<=m;i++) {
            if(n-cnt[i]<=k) F[i]=qpow(m/i,n-cnt[i])*C(cnt[i],k-n+cnt[i])%MOD*qpow(m/i-1,k-n+cnt[i])%MOD;
            else F[i]=0;
        }
        for(int i=1;i<=m;i++) {
            res[i]=0;
            for(int j=i;j<=m;j+=i)
                res[i]=(res[i]+mu[j/i]*F[j])%MOD;
        }
        for(int i=1;i<=m;i++) cout<<(res[i]+MOD)%MOD<<" \n"[i==m];
    }
    return 0;
}