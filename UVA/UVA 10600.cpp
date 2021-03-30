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
int n,m,fa[N],dist[N][N],mx[N][N];
bool vis[N][N];
int prim() {
    memset(fa,-1,sizeof fa);
    memset(mx,0,sizeof mx);
    memset(vis,false,sizeof vis);
    priority_queue<pair<int,PII>,vector<pair<int,PII>>,greater<pair<int,PII>>> q;
    int mst=0;
    q.emplace(0,MP(1,0));
    while(SZ(q)) {
        int u=q.top().SE.FI,f=q.top().SE.SE,w=q.top().FI;
        q.pop();
        if(fa[u]!=-1) continue;
        fa[u]=f;
        vis[u][fa[u]]=vis[fa[u]][u]=true;
        mx[fa[u]][u]=mx[u][fa[u]]=w;
        mst+=w;
        for(int v=1;v<=n;v++) {
            if(v==u) continue;
            if(fa[v]!=-1) mx[u][v]=mx[v][u]=max(mx[u][fa[u]],mx[fa[u]][v]);
            else q.emplace(dist[u][v],MP(v,u));
        }
    }
    return mst;
}
void solve() {
    int mst=prim(),res=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dist[i][j]!=0x3f3f3f3f&&!vis[i][j])
                res=min(res,mst+dist[i][j]-mx[i][j]);
    cout<<mst<<' '<<res<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        memset(dist,0x3f,sizeof dist);
        for(int i=1;i<=m;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            dist[u][v]=dist[v][u]=w;
        }
        solve();
    }
    return 0;
}