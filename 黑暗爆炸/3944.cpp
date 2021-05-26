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
const int LIM=2e6;
const int N=2e6+5;
int mn[N];
LL phi[N],mu[N];
VI p;
unordered_map<LL,LL> _phi,_mu;
void init(int n) {
    phi[1]=mu[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,mu[i]=-1,phi[i]=i-1,p.PB(i);
        for(auto x:p) {
            if(x*i>n) break;
            mn[x*i]=x;
            if(i%x==0) {mu[x*i]=0,phi[x*i]=phi[i]*x;break;}
            mu[x*i]=-mu[i];
            phi[x*i]=i%x?phi[i]*(x-1):phi[i]*x;
        }
    }
    for(int i=1;i<=n;i++) phi[i]+=phi[i-1],mu[i]+=mu[i-1];
}
LL calc_phi(LL n) {
    if(n<=LIM) return phi[n];
    if(_phi.count(n)) return _phi[n];
    LL ret=0;
    for(LL l=2,r;l<=n;l=r+1) {
        r=n/(n/l);
        ret+=(r-l+1)*calc_phi(n/l);
    }
    return _phi[n]=n*(n+1)/2-ret;
}
LL calc_mu(LL n) {
    if(n<=LIM) return mu[n];
    if(_mu.count(n)) return _mu[n];
    LL ret=0;
    for(LL l=2,r;l<=n;l=r+1) {
        r=n/(n/l);
        ret+=(r-l+1)*calc_mu(n/l);
    }
    return _mu[n]=1-ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(LIM);
    int T;cin>>T;
    while(T--) {
        LL n;cin>>n;
        cout<<calc_phi(n)<<' '<<calc_mu(n)<<'\n';
    }
    return 0;
}