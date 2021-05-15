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
const int N=105;
int n,m,fa[N],mx[N][N];
bool vis[N<<2];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
};
vector<E> e;
VI g[N];
int prim() {
    memset(fa,0,sizeof fa);
    memset(mx,0,sizeof mx);
    memset(vis,false,sizeof vis);
    priority_queue<PII,VPII,greater<PII>> q;
    int mst=0,cnt=0;
    q.emplace(0,-1);
    while(SZ(q)) {
        auto x=q.top();
        q.pop();
        int u;
        if(x.SE!=-1) {
            u=e[x.SE].v;
            int f=e[x.SE].u,w=e[x.SE].w;
            if(fa[u]) continue;
            fa[u]=f;
            vis[x.SE]=vis[x.SE^1]=true;
            mx[fa[u]][u]=mx[u][fa[u]]=w;
            mst+=w;
        }
        else u=fa[1]=1;
        ++cnt;
        for(int v=1;v<=n;v++) {
            if(v==u) continue;
            if(fa[v]) mx[u][v]=mx[v][u]=max(mx[u][fa[u]],mx[fa[u]][v]);
        }
        for(auto x:g[u]) {
            if(fa[e[x].v]) continue;
            q.emplace(e[x].w,x);
        }
    }
    return cnt==n?mst:-1;
}
void solve() {
    int mst=prim(),res=0x3f3f3f3f;
    if(mst==-1) {cout<<"No way"<<'\n';return;}
    for(int i=0;i<SZ(e);i+=2) {
        if(vis[i]) continue;
        res=min(res,mst+e[i].w-mx[e[i].u][e[i].v]);
    }
    if(res==0x3f3f3f3f) cout<<"No second way"<<'\n';
    else cout<<res<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for(int cs=1;cs<=T;cs++) {
        cin>>n>>m;
        e.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            if(u==v) continue;
            e.EB(u,v,w);
            e.EB(v,u,w);
            g[u].EB(SZ(e)-2);
            g[v].EB(SZ(e)-1);
        }
        cout<<"Case #"<<cs<<" : ";
        solve();
    }
    return 0;
}