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
const int N=105;
struct E_DCC {
    int n;
    vector<int> G[N];
    void init() {
        for(int i=1;i<=n;i++) G[i].clear();
    }
    //割边
    int cnt,dfn[N],low[N],fa[N];
    bool isb[N];
    VPII b;
    void tarjan(int u) {
        dfn[u]=low[u]=++cnt;
        for(auto v:G[u]) {
            if(!dfn[v]) {
                fa[v]=u;
                tarjan(v);
                low[u]=min(low[u],low[v]);
                if(dfn[u]<low[v]) isb[v]=true,b.push_back(MP(min(u,v),max(u,v)));
            }
            else if(v!=fa[u]) low[u]=min(low[u],dfn[v]);
        }
    }
    void get_bridge() {
        cnt=0;
        b.clear();
        for(int i=1;i<=n;i++) dfn[i]=low[i]=fa[i]=0,isb[i]=false;
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    }
    void solve() {
        while(~scanf("%d",&n)) {
            init();
            for(int i=1;i<=n;i++) {
                int u;
                scanf("%d",&u);
                u++;
                int x;
                scanf(" (%d)",&x);
                for(int i=1;i<=x;i++) {
                    int v;
                    scanf("%d",&v);
                    v++;
                    G[u].PB(v);
                    G[v].PB(u);
                }
            }
            get_bridge();
            printf("%d critical links\n",SZ(b));
            sort(ALL(b));
            for(auto x:b) printf("%d - %d\n",x.FI-1,x.SE-1);
            puts("");
        }
    }
}e_dcc;
int main() {
    //freopen("in.txt","r",stdin);
    e_dcc.solve();
    return 0;
}