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
const int N=2e4+5;
int n,m,s,t,cost,dist[N],cur[N];
bool st[N];
VI g[N];
VPII a,b;
char str[N][N];
struct E {
    int v,c,w;
    E() {}
    E(int v,int c,int w):v(v),c(c),w(w) {}
};
vector<E> e;
void add_edge(int u,int v,int c,int w) {
    e.PB(E(v,c,w));
    e.PB(E(u,0,-w));
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool spfa() {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f,st[i]=false;
    dist[s]=0;
    queue<int> q;
    q.push(s);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=e[g[u][i]].v,c=e[g[u][i]].c,w=e[g[u][i]].w;
            if(c>0&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                if(!st[v]) q.push(v),st[v]=true;
            }
        }
    }
    return dist[t]!=0x3f3f3f3f;
}
int dfs(int u,int a) {
    if(u==t) return a;
    int flow=0,f;
    st[u]=true;
    for(int &i=cur[u];i<SZ(g[u]);i++) {
        int v=e[g[u][i]].v,&c=e[g[u][i]].c,w=e[g[u][i]].w;
        if(st[v]||c<=0||dist[v]!=dist[u]+w||(f=dfs(v,min(a,c)))<=0) continue;
        c-=f;
        e[g[u][i]^1].c+=f;
        a-=f;
        flow+=f;
        cost+=w*f;
        if(!(a)) break;
    }
    st[u]=false;
    return flow;
}
void dinic() {
    while(spfa()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        dfs(s,0x3f3f3f3f);
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(!n&!m) break;
        s=1,t=2;
        for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
        a.clear(),b.clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                if(str[i][j]=='m') a.PB(MP(i,j));
                else if(str[i][j]=='H') b.PB(MP(i,j));
            }
        for(int i=0;i<SZ(a);i++)
            for(int j=0;j<SZ(b);j++)
                add_edge(i+1+2,SZ(a)+j+1+2,1,abs(a[i].FI-b[j].FI)+abs(a[i].SE-b[j].SE));
        for(int i=1;i<=SZ(a);i++) add_edge(s,i+2,1,0);
        for(int i=1;i<=SZ(b);i++) add_edge(SZ(a)+i+2,t,1,0);
        n=SZ(a)*2+2;
        dinic();
        printf("%d\n",cost);
        for(int i=1;i<=n;i++) g[i].clear();
        e.clear();
        cost=0;
    }
    return 0;
}