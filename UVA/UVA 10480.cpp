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
int n,m,s,t,d[N],cur[N];
bool st[N];
vector<pair<int,int>> e;
vector<int> g[N];
void init() {
    for(int i=1;i<=n;i++) g[i].clear(),st[i]=false;
    e.clear();
}
void add_edge(int u,int v,int c) {
    e.emplace_back(v,c);
    e.emplace_back(u,c);
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
void dinic() {
    while(bfs()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        dfs(s,0x3f3f3f3f);
    }
}
void dfs2(int u) {
    for(auto x:g[u]) {
        if(st[e[x].FI]||!e[x].SE) continue;
        st[e[x].FI]=true;
        dfs2(e[x].FI);
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(!n&&!m) break;
        init();
        for(int i=1;i<=m;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
        }
        s=1,t=2;
        dinic();
        st[s]=true;
        dfs2(s);
        for(int i=0;i<SZ(e);i+=2) if(st[e[i].FI]!=st[e[i^1].FI]) printf("%d %d\n",e[i^1].FI,e[i].FI);
        puts("");
    }
    return 0;
}