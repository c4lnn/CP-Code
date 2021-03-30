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
int n,m,cnt,dfn[N],low[N],top,stk[N],cnt_scc,c[N],id[N];
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
        for(int i=1;i<=n;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            id[a]=i,id[b]=id[c]=i+n;
        }
        for(int i=1;i<=m;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            G[id[a]].PB(id[b]<=n?id[b]+n:id[b]-n);
            G[id[b]].PB(id[a]<=n?id[a]+n:id[a]-n);
        }
        cnt=cnt_scc=top=0;
        for(int i=1;i<=n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
        for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
        bool f=false;
        for(int i=1;i<=n;i++) if(c[i]==c[i+n]) {f=true;break;}
        puts(f?"no":"yes");
    }
    return 0;
}