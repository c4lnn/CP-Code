#include <bits/stdc++.h>
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
const int N=2005;
vector<int> G[N];
int n,m,cnt,dfn[N],low[N],top,stk[N],cnt_scc,c[N];
bool ins[N];
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    stk[++top]=u;
    ins[u]=true;
    for(auto v:G[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        ++cnt_scc;
        int x;
        do {
            x=stk[top--];
            ins[x]=false;
            c[x]=cnt_scc;
        } while(u!=x);
    }
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n*2;i++) G[i].clear();
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            int u,v,p,q;
            scanf("%d%d%d%d",&u,&v,&p,&q);
            u++,v++;
            G[u+p*n].PB(v+(1-q)*n);
            G[v+q*n].PB(u+(1-p)*n);
        }
        cnt=cnt_scc=top=0;
        for(int i=1;i<=n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
        for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
        bool f=false;
        for(int i=1;i<=n;i++) if(c[i]==c[i+n]) {f=true;break;}
        puts(f?"NO":"YES");
    }
    return 0;
}