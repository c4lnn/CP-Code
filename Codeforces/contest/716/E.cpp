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
int n,m,sz[N],mx[N],a[N],dist[N],c[N],rt,cnt;
LL down[N],up[N],inv[N],power[N],b[N],res;
bool st[N];
VPII g[N];
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(!b) {x=1,y=0;return a;}
    LL ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
LL get_inv(LL a,LL m) {
    LL x,y;
    if(exgcd(a,m,x,y)!=1) return -1;
    return (x%m+m)%m;
}
void get_rt(int u,int fa,int sum) {
    sz[u]=1;
    mx[u]=0;
    for(auto x:g[u]) {
        int v=x.FI;
        if(v==fa||st[v]) continue;
        get_rt(v,u,sum);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
    mx[u]=max(mx[u],sum-sz[u]);
    if(mx[u]<mx[rt]) rt=u;
}
void get_dist(int u,int fa) {
    a[++cnt]=up[u];
    b[cnt]=(m-down[u])*inv[dist[u]]%m;
    c[cnt]=u;
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(v==fa||st[v]) continue;
        dist[v]=dist[u]+1;
        up[v]=(w*power[dist[u]]%m+up[u])%m;
        down[v]=(down[u]*10+w)%m;
        get_dist(v,u);
    }
}
LL calc(int u,int t) {
    cnt=0;
    if(t==-1) up[u]=down[u]=dist[u]=0;
    else {
        dist[u]=1;
        up[u]=down[u]=t%m;
    }
    get_dist(u,0);
    sort(a+1,a+1+cnt);
    sort(b+1,b+1+cnt);
    LL ret=0;
    int l1=1,l2=1;
    while(l1<=cnt&&l2<=cnt) {
        while(l1<=cnt&&a[l1]<b[l2]) ++l1;
        if(l1>cnt) break;
        int tot1=1;
        while(l1+1<=cnt&&a[l1+1]==a[l1]) ++tot1,++l1;
        while(l2<=cnt&&b[l2]<a[l1]) ++l2;
        if(l2>cnt) break;
        if(b[l2]==a[l1]) {
            int tot2=1;
            while(l2+1<=cnt&&b[l2+1]==b[l2]) ++tot2,++l2;
            ret+=1ll*tot1*tot2;
            ++l1,++l2;
        }
    }
    for(int i=1;i<=cnt;i++) if(up[c[i]]==(m-down[c[i]])*inv[dist[c[i]]]%m) --ret;
    return ret;
}
void divide(int u) {
    mx[rt=0]=INT_MAX;
    get_rt(u,0,sz[u]);
    st[u=rt]=true;
    res+=calc(u,-1);
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(st[v]) continue;
        res-=calc(v,w);
        divide(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v,w;cin>>u>>v>>w;
        ++u,++v;
        g[u].EB(v,w);
        g[v].EB(u,w);
    }
    if(m==1) return cout<<1ll*n*(n-1)<<'\n',0;
    power[0]=1;
    for(int i=1;i<=n;i++) power[i]=power[i-1]*10%m;
    inv[n]=get_inv(power[n],m);
    for(int i=n-1;~i;i--) inv[i]=inv[i+1]*10%m;
    sz[1]=n;divide(1);
    cout<<res<<'\n';
    return 0;
}