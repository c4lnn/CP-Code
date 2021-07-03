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
int mn[N];
LL mu[N],sum[N];
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
    for(int i=1;i<=n;i++) mu[i]=(mu[i-1]+MOD+mu[i])%MOD;
    for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+1ll*i*i%MOD)%MOD;
}
LL g(int n,int m) {
    int lim=min(n,m);
    LL ret=0;
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        ret=(ret+(mu[r]+MOD-mu[l-1])%MOD*(n/l)%MOD*(m/l)%MOD)%MOD;
    }
    return ret;
}
LL f(int n,int m) {
    int lim=min(n,m);
    LL ret=0;
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        ret=(ret+(sum[r]+MOD-sum[l-1])%MOD*g(n/l,m/l)%MOD)%MOD;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    get_mu(1e6);
    cout<<f(n,m)<<'\n';
    return 0;
}