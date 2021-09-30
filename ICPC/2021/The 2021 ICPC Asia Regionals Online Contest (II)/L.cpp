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
const int N=1e5+5;
const LL MOD=998244353;
int mn[105],phi[105],a[N],ls[N<<2],rs[N<<2],cnt[N],tag[N<<2],bit[105],tot[105][30];
LL sum[N<<2],laz[N<<2];
VI prime;
void get_phi(int n) {
    phi[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,prime.PB(i),phi[i]=i-1;
        for(auto x:prime) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
            phi[i*x]=i%x?phi[i]*(x-1):phi[i]*x;
        }
    }
}
void solve() {
    for(int i=2;i<=100;i++) {
        int t=i;
        for(int j=0;j<SZ(prime);j++) {
            int x=prime[j];
            if(t%x==0) {
                bit[i]|=1<<j;
                while(t%x==0) ++tot[i][j],t/=x;
            }
        }
    }
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r,laz[p]=1;
    if(l==r) {
        sum[p]=phi[a[l]];
        tag[p]=bit[a[l]];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    sum[p]=(sum[p<<1]+sum[p<<1|1])%MOD;
    tag[p]=tag[p<<1]&tag[p<<1|1];
}
void push_down(int p) {
    if(laz[p]!=1) {
        sum[p<<1]=sum[p<<1]*laz[p]%MOD;
        sum[p<<1|1]=sum[p<<1|1]*laz[p]%MOD;
        laz[p<<1]=laz[p<<1]*laz[p]%MOD;
        laz[p<<1|1]=laz[p<<1|1]*laz[p]%MOD;
        laz[p]=1;
    }
}
void update(int p,int l,int r,int x,int y) {
    if(ls[p]>=l&&rs[p]<=r&&(tag[p]>>x)&1) {
        for(int i=0;i<y;i++) {
            sum[p]=sum[p]*prime[x]%MOD;
            laz[p]=laz[p]*prime[x]%MOD;
        }
        return;
    }
    if(ls[p]==rs[p]) {
        sum[p]=sum[p]*(prime[x]-1)%MOD;
        tag[p]|=(1<<x);
        for(int i=0;i<y-1;i++) sum[p]=sum[p]*prime[x]%MOD;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,x,y);
    if(r>mid) update(p<<1|1,l,r,x,y);
    sum[p]=(sum[p<<1]+sum[p<<1|1])%MOD;
    tag[p]=tag[p<<1]&tag[p<<1|1];
}
LL query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return sum[p];
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return (query(p<<1,l,r)+query(p<<1|1,l,r))%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_phi(100);
    solve();
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=m;i++) {
        int o,l,r;cin>>o>>l>>r;
        if(!o) {
            int v;cin>>v;
            for(int j=0;j<25;j++) if(tot[v][j]) update(1,l,r,j,tot[v][j]);
        }
        else {
            cout<<query(1,l,r);
            if(i!=m) cout<<'\n';
        }
    }
    return 0;
}