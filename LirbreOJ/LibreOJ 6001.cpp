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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=105;
const int INF=0x3f3f3f3f;
int n,m,sum,s,t,d[N],cur[N];
vector<pair<int,int>> e;
vector<int> g[N];
void init() {
    for(int i=1;i<=n;i++) g[i].clear();
    e.clear();
}
void add_edge(int u,int v,int c) {
    e.emplace_back(v,c);
    e.emplace_back(u,0);
    g[u].push_back(e.size()-2);
    g[v].push_back(e.size()-1);
}
bool bfs() {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    q.push(s);
    d[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto x:g[u]) {
            int v=e[x].first,c=e[x].second;
            if(d[v]||c<=0) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    return d[t];
}
int dfs(int u,int a) { // 多路增广
    if(u==t) return a;
    int f,flow=0;
    for(int &i=cur[u];i<g[u].size();i++) {
        int v=e[g[u][i]].first,&c=e[g[u][i]].second;
        if(d[v]!=d[u]+1||c<=0||(f=dfs(v,min(a,c)))<=0) continue;
        c-=f;
        e[g[u][i]^1].second+=f;
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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&m,&n);
    s=n+m+1;
    t=s+1;
    for(int i=1;i<=m;i++) {
        int c;
        scanf("%d",&c);
        sum+=c;
        add_edge(s,n+i,c);
        int v;
        while(~scanf("%d",&v)) {
            add_edge(n+i,v,INF);
            char t=getchar();
            if(t!=' ') break;
        }
    }
    for(int i=1;i<=n;i++) {
        int c;
        scanf("%d",&c);
        add_edge(i,t,c);
    }
    n=t;
    sum-=dinic();
    n=s-1-m;
    VI a,b;
    for(int i=1;i<=m;i++) if(d[n+i]) a.PB(i);
    for(int i=0;i<SZ(a);i++) printf("%d%c",a[i],i==SZ(a)-1?'\n':' ');
    for(int i=1;i<=n;i++) if(d[i]) b.PB(i);
    for(int i=0;i<SZ(b);i++) printf("%d%c",b[i],i==SZ(b)-1?'\n':' ');
    printf("%d\n",sum);
    return 0;
}