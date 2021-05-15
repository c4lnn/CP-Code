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
const int N=5e3+5;
int n,m,o,s,t,cost,a[55][55],b[55][55],dist[N],cur[N];
bool st[N];
VI g[N];
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
int dinic() {
    int flow=0;
    while(spfa()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        flow+=dfs(s,0x3f3f3f3f);
    }
    return flow;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&o)) {
        if(!n&&!m&&!o) break;
        bool f=false;
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=o;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=o;j++)
                scanf("%d",&b[i][j]);

        s=n+m+1;
        t=s+1;
        for(int i=1;i<=o;i++) {
            cost=0;
            n=t-m-2;
            for(int i=1;i<=t;i++) g[i].clear();
            e.clear();
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++) {
                    int w;
                    scanf("%d",&w);
                    add_edge(k,m+j,0x3f3f3f3f,w);
                }
            if(f) continue;
            for(int j=1;j<=m;j++) add_edge(s,j,b[j][i],0);
            int sum=0;
            for(int j=1;j<=n;j++) sum+=a[j][i],add_edge(m+j,t,a[j][i],0);
            n=t;
            if(dinic()!=sum) f=true;
            else res+=cost;
        }
        if(f) puts("-1");
        else printf("%d\n",res);
    }
    return 0;
}