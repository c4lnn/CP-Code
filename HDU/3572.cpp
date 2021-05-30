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
const int N=1005;
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
int c[505];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n,m;cin>>n>>m;
        int sum=0;
        mf.s=0;
        for(int i=1;i<=n;i++) {
            int a,b;cin>>c[i]>>a>>b;
            sum+=c[i];
            mf.s=max(mf.s,n+b);
            for(int j=a;j<=b;j++) mf.add_edge(i,n+j,1);
        }
        mf.n=mf.t=mf.s+1;
        for(int i=1;i<=n;i++) mf.add_edge(mf.s,i,c[i]);
        for(int i=n+1;i<mf.s;i++) mf.add_edge(i,mf.t,m);
        cout<<"Case "<<cs<<": "<<(mf.dinic()==sum?"Yes":"No")<<"\n\n";
        mf.init();
    }
    return 0;
}