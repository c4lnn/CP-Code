#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
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
const int N=1005;
int n,m,cnt,cnt_dcc,res,dfn[N],low[N],c[N],fa[N];
bool isb[N];
VI b,G[N],g[N];
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    for(int i=0;i<SZ(G[u]);i++) {
        int v=G[u][i];
        if(!dfn[v]) {
            fa[v]=u;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) {
                isb[v]=true;
                b.PB(v);
            }
        }
        else if(v!=fa[u]) low[u]=min(low[u],dfn[v]);
    }
}
void dfs(int u) {
    c[u]=cnt_dcc;
    for(int i=0;i<SZ(G[u]);i++) {
        int v=G[u][i];
        if(c[v]||u==fa[v]&&isb[v]||fa[u]==v&&isb[u]) continue;
        dfs(v);
    }
}
void build() {
    for(int i=0;i<SZ(b);i++) {
        int u=c[b[i]],v=c[fa[b[i]]];
        g[u].PB(v);
        g[v].PB(u);
    }
}
void dfs2(int u,int pre) {
    int sz=0;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i];
        if(v==pre) continue;
        dfs2(v,u);
        sz++;
    }
    if(u==1&&sz==1||u!=1&&sz==0) res++;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
        G[v].PB(u);
    }
    tarjan(1);
    for(int i=1;i<=n;i++) if(!c[i]) ++cnt_dcc,dfs(i);
    build();
    dfs2(1,0);
    printf("%d\n",(res+1)/2);
    return 0;
}