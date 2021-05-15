#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int n,np,nc,m,s,t,d[N],cur[N];
VPII e;
VI g[N];
void add_edge(int u,int v,int c) {
    e.PB(MP(v,c));
    e.PB(MP(u,0));
    g[u].PB(e.size()-2);
    g[v].PB(e.size()-1);
}
bool bfs() {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    q.push(s);
    d[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0;i<SZ(g[u]);i++) {
            int v=e[g[u][i]].first,c=e[g[u][i]].second;
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
        flow+=dfs(s,0x3f3f3f3f);
    }
    return flow;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m)) {
        s=n+1,t=s+1;
        for(int i=1;i<=t;i++) g[i].clear();
        e.clear();
        for(int i=1;i<=m;i++) {
            int u,v,c;
            scanf(" (%d,%d)%d",&u,&v,&c);
            add_edge(u+1,v+1,c);
        }

        for(int i=1;i<=np;i++) {
            int x,c;
            scanf(" (%d)%d",&x,&c);
            add_edge(s,x+1,c);
        }
        for(int i=1;i<=nc;i++) {
            int x,c;
            scanf(" (%d)%d",&x,&c);
            add_edge(x+1,t,c);
        }
        n=t;
        printf("%d\n",dinic());
    }
    return 0;
}