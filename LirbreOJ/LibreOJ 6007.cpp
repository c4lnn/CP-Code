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
const int N=3000;
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
int dfs(int u,int a) {
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
    scanf("%d%d",&n,&m);
    s=n*m+1;
    t=s+1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int c;
            scanf("%d",&c);
            sum+=c;
            if((i+j)&1) {
                add_edge(s,i*m+j+1,c);
                if(i-1>=0) add_edge(i*m+j+1,(i-1)*m+j+1,INF);
                if(i+1<n) add_edge(i*m+j+1,(i+1)*m+j+1,INF);
                if(j-1>=0) add_edge(i*m+j+1,i*m+j,INF);
                if(j+1<m) add_edge(i*m+j+1,i*m+j+2,INF);
            }
            else add_edge(i*m+j+1,t,c);
        }
    }
    n=t;
    printf("%d\n",sum-dinic());
    return 0;
}