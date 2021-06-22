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
const int N=1e4+5;
int n,m,q[105],cnt,rt,sz[N],mx[N],dist[N],a[N],b[N];
bool st[N],f[105];
VPII g[N];
void get_rt(int u,int fa,int sum) {
    sz[u]=1;
    mx[u]=0;
    for(auto x:g[u]) {
        int v=x.FI;
        if(v==fa||st[v]) continue;
        get_rt(v,u,sum);
        mx[u]=max(mx[u],sz[v]);
        sz[u]+=sz[v];
    }
    mx[u]=max(mx[u],sum-sz[u]);
    if(mx[u]<mx[rt]) rt=u;
}
void get_dist(int u,int fa) {
    a[++cnt]=u;
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(st[v]||v==fa) continue;
        dist[v]=dist[u]+w;
        b[v]=b[u];
        get_dist(v,u);
    }
}
bool cmp(int a,int b) {
    return dist[a]<dist[b];
}
void calc(int u) {
    dist[u]=0;
    cnt=0;
    a[++cnt]=u;
    b[u]=u;
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(st[v]) continue;
        dist[v]=w;
        b[v]=v;
        get_dist(v,v);
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=m;i++) if(!f[i]) {
        int l=1,r=cnt;
        while(l<r) {
            int t=dist[a[l]]+dist[a[r]];
            if(t<q[i]) ++l;
            else if(t>q[i]) --r;
            else if(b[a[l]]==b[a[r]]) {
                if(dist[a[r]]==dist[a[r-1]]) --r;
                else ++l;
            }
            else {f[i]=true;break;}
        }
    }
}
void divide(int u) {
    rt=0,mx[rt]=INT_MAX;
    get_rt(u,0,sz[u]);
    u=rt;
    st[u]=true;
    calc(u);
    for(auto x:g[u]) {
        int v=x.FI;
        if(st[v]) continue;
        divide(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v,w;cin>>u>>v>>w;
        g[u].EB(v,w);
        g[v].EB(u,w);
    }
    for(int i=1;i<=m;i++) {
        cin>>q[i];
    }
    sz[1]=n;divide(1);
    for(int i=1;i<=m;i++) {
        cout<<(f[i]?"AYE":"NAY")<<'\n';
    }
    return 0;
}