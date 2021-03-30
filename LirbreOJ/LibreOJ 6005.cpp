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
const int N=1005;
const int INF=0x3f3f3f3f;
int n,a[N],dp[N],mx,cur[N],d[N],s,t;
VI g[N];
VPII e;
void add_edge(int u,int v,int c) {
    e.EB(v,c);
    e.EB(u,0);
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
    int flow=0,f;
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
        flow+=dfs(s,INF);
    }
    return flow;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    if(n==1) {puts("1\n1\n1");return 0;}
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        dp[i]=1;
        for(int j=1;j<i;j++) if(a[i]>=a[j]) dp[i]=max(dp[i],dp[j]+1);
        mx=max(mx,dp[i]);
    }
    printf("%d\n",mx);
    s=n+n+1;
    t=s+1;
    for(int i=1;i<=n;i++) if(dp[i]==1) add_edge(s,i,1);
    for(int i=1;i<=n;i++) add_edge(i,i+n,1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(dp[i]==dp[j]+1&&a[i]>=a[j]) {
                add_edge(j+n,i,1);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(dp[i]==mx) {
            add_edge(n+i,t,1);
        }
    }
    n=t;
    int res=dinic();
    printf("%d\n",res);
    n=s-1>>1;
    add_edge(1,1+n,INF);
    add_edge(n,n+n,INF);
    add_edge(s,1,INF);
    if(dp[n]==mx) add_edge(n+n,t,INF);
    n=t;
    res+=dinic();
    printf("%d\n",res);
    return 0;
}