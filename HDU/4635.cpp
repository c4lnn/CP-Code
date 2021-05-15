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
const int N=1e5+5;
struct SCC {
    int n,m;
    vector<int> G[N];
    void init() {
        for(int i=1;i<=n;i++) G[i].clear();
    }
    //强连通分量
    int cnt,dfn[N],low[N],top,stack[N],cnt_scc,c[N];
    bool ins[N];
    vector<int> scc[N];
    void tarjan(int u) {
        dfn[u]=low[u]=++cnt;
        stack[++top]=u;
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
                x=stack[top--];
                ins[x]=false;
                c[x]=cnt_scc;
                scc[cnt_scc].push_back(x);
            } while(u!=x);
        }
    }
    void shrink() {
        for(int i=1;i<=cnt_scc;i++) scc[i].clear();
        cnt=cnt_scc=top=0;
        for(int i=1;i<=n;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    }
    // 缩点建图
    int in[N],out[N];
    void build() {
        for(int i=1;i<=cnt_scc;i++) in[i]=out[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<G[i].size();j++) {
                int u=c[i],v=c[G[i][j]];
                if(u==v) continue;
                in[u]++;
                out[v]++;
            }
    }
    //solve
    void solve() {
        int T;
        scanf("%d",&T);
        for(int cs=1;cs<=T;cs++) {
            scanf("%d%d",&n,&m);
            init();
            for(int i=1;i<=m;i++) {
                int u,v;
                scanf("%d%d",&u,&v);
                G[u].PB(v);
            }
            shrink();
            build();
            int mn=INT_MAX;
            for(int i=1;i<=cnt_scc;i++)
                if(!in[i]||!out[i])
                    mn=min(mn,SZ(scc[i]));
            printf("Case %d: %lld\n",cs,cnt_scc==1?-1:1ll*n*(n-1)-m-1ll*mn*(n-mn));
        }
    }
}scc;
int main() {
    //freopen("D:/Program Files (x86)/Sublime Text 3/in.txt","r",stdin);
    scc.solve();
    return 0;
}