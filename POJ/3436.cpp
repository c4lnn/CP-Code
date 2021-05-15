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
const int N=55;
int n,p,q[N],a[N][N],b[N][N],s,t,d[N],cur[N];
VI g[N];
VPII e;
struct R {
    int u,v,c;
    R() {}
    R(int u,int v,int c):u(u),v(v),c(c) {}
};
vector<R> res;
void add_edge(int u,int v,int c) {
    e.PB(MP(v,c));
    e.PB(MP(u,0));
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool bfs() {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    d[s]=1;
    q.push(s);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int i=0;i<SZ(g[u]);i++) {
            int v=e[g[u][i]].FI,c=e[g[u][i]].SE;
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
        if(!a) break;
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
    scanf("%d%d",&p,&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&q[i]);
        for(int j=1;j<=p;j++) scanf("%d",&a[i][j]);
        for(int j=1;j<=p;j++) scanf("%d",&b[i][j]);
    }
    s=n+n+1;
    t=s+1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=p;j++) {
            if(a[i][j]==1) break;
            if(j==p) add_edge(s,i,q[i]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=p;j++) {
            if(b[i][j]==0) break;
            if(j==p) add_edge(i+n,t,q[i]);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=p;k++) {
                if(b[i][k]==0&&a[j][k]==1||b[i][k]==1&&a[j][k]==0) break;
                if(k==p) add_edge(i+n,j,q[i]);
            }
    for(int i=1;i<=n;i++) add_edge(i,i+n,q[i]);
    n=t;
    printf("%d ",dinic());
    n=s-1>>1;
    for(int i=1;i<SZ(e);i+=2) if(e[i^1].FI<=n&&e[i].FI>n&&e[i].FI<=n+n&&e[i].SE) res.PB(R(e[i].FI-n,e[i^1].FI,e[i].SE));
    printf("%d\n",SZ(res));
    for(int i=0;i<SZ(res);i++) printf("%d %d %d\n",res[i].u,res[i].v,res[i].c);
    return 0;
}