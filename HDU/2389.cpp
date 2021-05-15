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
const int N=3005;
int n,m,match[N<<1],dep[N<<1];
DB o,x[N<<1],y[N<<1],z[N];
VI g[N];
bool bfs() {
    queue<int> q;
    for(int i=1;i<=n+m;i++) dep[i]=0;
    for(int i=1;i<=n;i++) if(match[i]==-1) dep[i]=1,q.push(i);
    bool f=false;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(dep[v]) continue;
            dep[v]=dep[u]+1;
            if(match[v]==-1) f=true;
            else dep[match[v]]=dep[v]+1,q.push(match[v]);
        }
    }
    return f;
}
bool dfs(int u) {
    for(auto v:g[u]) {
        if(dep[v]!=dep[u]+1) continue;
        dep[v]=0;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int solve() {
    scanf("%lf%d",&o,&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
    scanf("%d",&m);
    for(int i=n+1;i<=n+m;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=n+m;j++)
            if(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<=o*z[i])
                g[i].PB(j);
    for(int i=1;i<=n+m;i++) match[i]=-1;
    int res=0;
    while(bfs()) for(int i=1;i<=n;i++) if(match[i]==-1&&dfs(i)) res++;
    return res;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        printf("Scenario #%d:\n%d\n",cs,solve());
        puts("");
    }
    return 0;
}