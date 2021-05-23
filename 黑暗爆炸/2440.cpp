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
const int N=1e5+5;
int mn[N],mu[N],sum[N];
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
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+mu[i];
}
LL solve(int n) {
    LL ret=0;
    for(int l=1,r;l*l<=n;l=r+1) {
        r=sqrt(n/(n/(l*l)));
        ret+=(sum[r]-sum[l-1])*(n/(l*l));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_mu(1e5);
    int T;cin>>T;
    while(T--) {
        int k;cin>>k;
        int l=1,r=2e9;
        while(l<r) {
            int mid=1ll*l+r>>1;
            if(solve(mid)>=k) r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}