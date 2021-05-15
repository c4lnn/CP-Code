#include<bits/stdc++.h>
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
const int N=1e3+5;
int n,m,cnt,dfn[N],low[N];
VPII e;
VI b,G[N];
void addEdge(int u,int v,int w) {
    e.PB(MP(v,w));
    e.PB(MP(u,w));
    G[u].PB(SZ(e)-2);
    G[v].PB(SZ(e)-1);
}
void tarjan(int u,int id) {
    dfn[u]=low[u]=++cnt;
    for(auto x:G[u]) {
        int v=e[x].FI,w=e[x].SE;
        if(!dfn[v]) {
            tarjan(v,x);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) b.PB(w);
        }
        else if(id!=(x^1)) low[u]=min(low[u],dfn[v]);
    }
}
void getBridge() {
    b.clear();
    e.clear();
    cnt=0;
    for(int i=1;i<=n;i++) dfn[i]=low[i]=0;
    int t=0;
    for(int i=1;i<=n;i++) if(!dfn[i]) t++,tarjan(i,-1);
    int res=0x3f3f3f3f;
    for(auto x:b) res=min(res,x);
    if(t>1) puts("0");
    else if(res==0x3f3f3f3f) puts("-1");
    else if(res==0) puts("1");
    else printf("%d\n",res);
}
int main() {
    //freopen("D:/Program Files (x86)/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
        getBridge();
    }
    return 0;
}