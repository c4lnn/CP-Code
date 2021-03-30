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
const int N=2005;
int n,n1,n2;
int cnt,dfn[N],low[N],cnt_scc,top,stk[N],c[N],match[N];
bool vis[N][N],ins[N],st[N];
VI G[N],scc[N];
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
            if(x>n1&&x<=n1+n2) scc[cnt_scc].PB(x);
        } while(u!=x);
    }
}
void shrink() {
    for(int i=1;i<=cnt_scc;i++) scc[i].clear();
    cnt=cnt_scc=top=0;
    for(int i=1;i<=n;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=cnt_scc;i++) sort(ALL(scc[i]));
}
bool dfs(int u) {
    for(auto v:G[u]) {
        if(st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}
void hungary() {
    int res=0;
    for(int i=1;i<=n;i++) match[i]=-1;
    for(int i=1;i<=n1;i++) {
        for(int j=1;j<=n;j++) st[j]=false;
        dfs(i);
    }
}
int main() {
    //freopen("D:/Program Files (x86)/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++) {
        for(int i=1;i<=n;i++) {
            G[i].clear();
            for(int j=1;j<=n;j++)
                vis[i][j]=false;
        }
        scanf("%d%d",&n1,&n2);
        for(int u=1;u<=n1;u++) {
            int t;
            scanf("%d",&t);
            for(int j=1;j<=t;j++) {
                int v;
                scanf("%d",&v);
                v+=n1;
                G[u].PB(v);
                vis[u][v]=true;
            }
        }
        n=n1+n2;
        hungary();
        int t=0;
        for(int i=n1+1;i<=n1+n2;i++) {
            if(match[i]!=-1) continue;
            n++;
            t++;
            match[n]=i;
            match[i]=n;
            for(int j=n1+1;j<=n1+n2;j++)
                G[n].PB(j);
        }
        for(int i=1;i<=n1;i++) {
            if(match[i]!=-1) continue;
            n++;
            match[i]=n;
            match[n]=i;
            for(int j=1;j<=n1;j++)
                G[j].PB(n);
        }
        for(int i=1;i<=n1;i++) G[match[i]].PB(i);
        for(int i=n1+n2+1;i<=n1+n2+t;i++) G[match[i]].PB(i);
        shrink();
        printf("Case #%d:\n",cs);
        VI res;
        for(int u=1;u<=n1;u++) {
            for(auto v:scc[c[u]])
                if(vis[u][v])
                    res.PB(v-n1);
            printf("%d",SZ(res));
            for(auto x:res)
                printf(" %d",x);
            puts("");
            res.clear();
        }
    }
    return 0;
}