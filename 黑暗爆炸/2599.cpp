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
const int N=2e5+5;
int n,k,sz[N],mx[N],dist[N],dep[N],a[N],b[N],mn[N*5],cnt,rt,res=0x3f3f3f3f;
bool st[N];
VPII g[N];
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
        if(v==fa||st[v]||dist[u]+w>k) continue;
        dist[v]=dist[u]+w;
        dep[v]=dep[u]+1;
        a[++cnt]=v;
        b[v]=t;
        dfs(v,u,t);
    }
}
bool cmp(int x,int y) {
    return b[x]<b[y];
}
void calc(int u) {
    dist[u]=dep[u]=0;
    a[cnt=1]=u;
    b[u]=0;
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(st[v]||w>k) continue;
        a[++cnt]=v;
        b[v]=v;
        dist[v]=dist[u]+w;
        dep[v]=dep[u]+1;
        dfs(v,u,v);
    }
    sort(a+1,a+1+cnt,cmp);
    int l=1,r=0;
    for(int i=1;i<=cnt;i++) {
        if(b[a[i]]==b[a[l]]) ++r;
        else {
            for(int j=l;j<=r;j++) mn[dist[a[j]]]=min(mn[dist[a[j]]],dep[a[j]]);
            l=r=i;
        }
        res=min(res,dep[a[i]]+mn[k-dist[a[i]]]);
    }
    for(int i=1;i<=cnt;i++) mn[dist[a[i]]]=0x3f3f3f3f;
}
void divide(int u) {
    mx[rt=0]=INT_MAX;
    get_rt(u,0,sz[u]);
    st[u=rt]=true;
    calc(u);
    for(auto x:g[u]) {
        int v=x.FI;
        if(st[v]) continue;
        divide(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v,w;cin>>u>>v>>w;
        ++u,++v;
        g[u].EB(v,w);
        g[v].EB(u,w);
    }
    memset(mn,0x3f,sizeof mn);
    sz[1]=n;divide(1);
    cout<<(res==0x3f3f3f3f?-1:res)<<'\n';
    return 0;
}