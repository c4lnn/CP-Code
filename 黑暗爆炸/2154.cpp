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
const LL MOD=20101009;
const int N=1e7+5;
int mn[N],mu[N];
LL sum1[N],sum2[N];
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
    for(int i=1;i<=n;i++) {
        sum1[i]=(sum1[i-1]+i)%MOD;
        sum2[i]=(sum2[i-1]+(1ll*i*i*mu[i]%MOD+MOD)%MOD)%MOD;
    }
}
LL g(int n,int m) {
    return (1ll*n*(n+1)/2%MOD)*(1ll*m*(m+1)/2%MOD)%MOD;
}
LL f(int n,int m) {
    LL ret=0;
    int lim=min(n,m);
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        ret=(ret+((sum2[r]-sum2[l-1])%MOD+MOD)%MOD*g(n/l,m/l)%MOD)%MOD;
    }
    return ret;
}
LL solve(int n,int m) {
    LL ret=0;
    int lim=min(n,m);
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        ret=(ret+((sum1[r]-sum1[l-1])%MOD+MOD)%MOD*f(n/l,m/l)%MOD)%MOD;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_mu(1e7);
    int n,m;cin>>n>>m;
    cout<<solve(n,m)<<'\n';
    return 0;
}