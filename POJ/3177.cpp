#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<functional>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=5e3+5;
int n,m;
struct E_DCC {
    vector<int> G[N];
    void init() {
        for(int i=1;i<=n;i++) G[i].clear();
    }
    //割边
    int cnt,dfn[N],low[N],fa[N];
    bool isb[N];
    vector<int> b;
    void tarjan(int u) {
        dfn[u]=low[u]=++cnt;
        for(int i=0;i<SZ(G[u]);i++) {
            int v=G[u][i];
            if(!dfn[v]) {
                fa[v]=u;
                tarjan(v);
                low[u]=min(low[u],low[v]);
                if(dfn[u]<low[v]) isb[v]=true,b.push_back(v);
            }
            else if(v!=fa[u]) low[u]=min(low[u],dfn[v]);
        }
    }
    void get_bridge() {
        for(int i=1;i<=n;i++) if(!dfn[i]) root=i,tarjan(i);
    }
    //边双连通分量
    int dcc,c[N];
    void dfs(int u) {
        c[u]=dcc;
        for(int i=0;i<SZ(G[u]);i++) {
            int v=G[u][i];
            if(c[v]||u==fa[v]&&isb[v]||v==fa[u]&&isb[u]) continue;
            dfs(v);
        }
    }
    void shrink() {
        for(int i=1;i<=n;i++) if(!c[i]) ++dcc,dfs(i);
    }
    //缩点建图
    vector<int> g[N];
    void build() { //将边双连通分量缩点与桥形成一棵树,原图不连通则形成森林
        for(int i=0;i<b.size();i++) {
            int u=c[b[i]],v=c[fa[b[i]]];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int sum,root;
    bool st[N];
    void dfs1(int u,int fa) {
        st[u]=true;
        int f=0;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i];
            if(v==fa) continue;
            f++;
            dfs1(v,u);
        }
        if(u!=root&&!f||u==root&&f==1) sum++;
    }
    void solve() {
        while(~scanf("%d%d",&n,&m)) {
            init();
            for(int i=1;i<=m;i++) {
                int u,v;
                scanf("%d%d",&u,&v);
                G[u].PB(v);
                G[v].PB(u);
            }
            get_bridge();
            shrink();
            build();
            int t=0,res=0;
            for(int i=1;i<=dcc;i++) {
                if(st[i]) continue;
                t++;
                sum=0;
                root=i;
                dfs1(i,0);
                if(sum>1) res+=(sum+1)/2;
            }
            printf("%d\n",t>1?res+t:res);
        }
    }
}e_dcc;
int main() {
    e_dcc.solve();
    return 0;
}