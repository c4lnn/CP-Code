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
const int N=1e3+5;
VI g[N];
VPII e;
int n,m,cnt,dfn[N],low[N],fa[N],res;
void init() {
    res=0x3f3f3f3f;
    cnt=0;
    e.clear();
    for(int i=1;i<=n;i++) g[i].clear(),dfn[i]=low[i]=0;
}
void add_edge(int u,int v,int w) {
    e.EB(v,w);
    e.EB(u,w);
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
void tarjan(int u,int id) {
    dfn[u]=low[u]=++cnt;
    for(auto x:g[u]) {
        int v=e[x].FI;
        if(!dfn[v]) {
            fa[v]=u;
            tarjan(v,x);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) res=min(res,e[x].SE);
        }
        else if(id!=(x^1)) low[u]=min(low[u],dfn[v]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m) {
        if(!n&&!m) break;
        init();
        for(int i=0;i<m;i++) {
            int u,v,w;cin>>u>>v>>w;
            add_edge(u,v,w);
        }
        int t=0;
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,-1),++t;
        if(t!=1) cout<<0<<'\n';
        else {
            if(!res) ++res;
            cout<<(res==0x3f3f3f3f?-1:res)<<'\n';
        }
    }
    return 0;
}