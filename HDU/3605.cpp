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
const int N=100100;
struct MAXIMUM_FLOW {
    const int INF=0x3f3f3f3f;
    int n,s,t,d[N],cur[N];
    VI g[N];
    VPII e;
    void init() {
        for(int i=1;i<=n;i++) g[i].clear();
        e.clear();
    }
    void add_edge(int u,int v,int c) {
        e.EB(v,c);
        e.EB(u,0);
        g[u].PB(SZ(e)-2);
        g[v].PB(SZ(e)-1);
    }
    bool bfs() {
        for(int i=1;i<=n;i++) d[i]=0;
        queue<int> q;
        q.push(s);
        d[s]=1;
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            for(auto x:g[u]) {
                int v=e[x].FI,c=e[x].SE;
                if(d[v]||c<=0) continue;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
        return d[t];
    }
    int dfs(int u,int a) {
        if(u==t) return a;
        int f,flow=0;
        for(int &i=cur[u];i<SZ(g[u]);i++) {
            int v=e[g[u][i]].FI,&c=e[g[u][i]].SE;
            if(d[v]!=d[u]+1||c<=0||(f=dfs(v,min(a,c)))<=0) continue;
            c-=f;
            e[g[u][i]^1].SE+=f;
            a-=f;
            flow+=f;
            if(a==0) break;
        }
        return flow;
    }
    int dinic() {
        int flow=0;
        while(bfs()) {
            for(int i=1;i<=n;i++) cur[i]=0;
            flow+=dfs(s,INF);
        }
        return flow;
    }
}mf;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    while(cin>>n>>m) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int x;cin>>x;
                if(x) mf.add_edge(i,n+j,1);
            }
        }
        mf.s=n+m+1,mf.t=mf.n=mf.s+1;
        for(int i=1;i<=n;i++) mf.add_edge(mf.s,i,1);
        for(int i=1;i<=m;i++) {
            int w;cin>>w;
            mf.add_edge(n+i,mf.t,w);
        }
        cout<<(mf.dinic()==n?"YES":"NO")<<'\n';
        mf.init();
    }
    return 0;
}