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
const int N=3e4+5;
int n,m,k,rt,cnt,a[N],b[N],dist[N],dep[N],sz[N],mx[N];
bool st[N];
VPII g[N];
PII pre[N],c[N];
pair<int,LL> res;
void dijkstra() {
    for(int i=1;i<=n;i++) {
        dist[i]=0x3f3f3f3f;
        st[i]=false;
    }
    priority_queue<PII,VPII,greater<PII>> q;
    q.emplace(0,1);
    dist[1]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.FI,w=x.SE;
            if(!st[v]&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                pre[v]=MP(u,w);
                q.emplace(dist[v],v);
            }
        }
    }
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=2;i<=n;i++) {
        g[pre[i].FI].EB(i,pre[i].SE);
        g[i].EB(pre[i].FI,pre[i].SE);
    }
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
void dfs(int u,int fa,int t) {
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(v==fa||st[v]) continue;
        dist[v]=dist[u]+w;
        dep[v]=dep[u]+1;
        b[v]=t;
        a[++cnt]=v;
        dfs(v,u,t);
    }
}
void calc(int u,int fa) {
    dist[u]=0;
    dep[u]=0;
    a[cnt=1]=u;
    b[u]=0;
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(v==fa||st[v]) continue;
        dist[v]=w;
        dep[v]=1;
        b[v]=v;
        a[++cnt]=v;
        dfs(v,u,v);
    }
    sort(a+1,a+1+cnt,[](int x,int y) {
        return b[x]<b[y];
    });
    int l=1,r=0;
    for(int i=1;i<=cnt;i++) {
        if(b[a[i]]==b[a[l]]) ++r;
        else {
            for(int j=l;j<=r;j++) {
                if(dist[a[j]]>c[dep[a[j]]].FI) c[dep[a[j]]]=MP(dist[a[j]],1);
                else if(dist[a[j]]==c[dep[a[j]]].FI) ++c[dep[a[j]]].SE;
            }
            l=r=i;
        }
        if(k-dep[a[i]]<0) continue;
        if(dist[a[i]]+c[k-dep[a[i]]].FI>res.FI) res=MP(dist[a[i]]+c[k-dep[a[i]]].FI,c[k-dep[a[i]]].SE);
        else if(dist[a[i]]+c[k-dep[a[i]]].FI==res.FI) res.SE+=c[k-dep[a[i]]].SE;
    }
    for(int i=1;i<=cnt;i++) {
        c[dep[a[i]]]=MP(0xc0c0c0c0,0);
    }
}
void divide(int u) {
    mx[rt=0]=INT_MAX;
    get_rt(u,0,sz[u]);
    st[u=rt]=true;
    calc(u,0);
    for(auto x:g[u]) {
        int v=x.FI;
        if(st[v]) continue;
        divide(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>n>>m>>k;
        --k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;cin>>u>>v>>w;
            g[u].EB(v,w);
            g[v].EB(u,w);
        }
        for(int i=1;i<=n;i++) sort(ALL(g[i]));
        dijkstra();
        res=MP(0,0);
        for(int i=0;i<=n;i++) {
            st[i]=false;
            c[i]=MP(0xc0c0c0c0,0);
        }
        sz[1]=n;divide(1);
        cout<<res.FI<<' '<<res.SE<<'\n';
    }
    return 0;
}