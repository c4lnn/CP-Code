#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int dist[N][N],dp[N][N],mn[N],pre[N],u[N*100],v[N*100],w[N*100];
bool st[N];
void prim(int n) {
    priority_queue<PII,VPII,greater<PII> > q;
    for(int i=1;i<=n;i++) mn[i]=0x3f3f3f3f;
    q.push(MP(0,1));
    mn[1]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int v=1;v<=n;v++) if(u!=v) {
            if(st[v]) dp[u][v]=dp[v][u]=max(dp[pre[u]][v],mn[u]);
            else if(dist[u][v]<mn[v]) {
                mn[v]=dist[u][v];
                pre[v]=u;
                q.push(MP(mn[v],v));
            }
        }
    }
}
int main() {
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dist[i][j]=dist[j][i]=0x3f3f3f3f;
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        dist[u[i]][v[i]]=dist[v[i]][u[i]]=min(dist[u[i]][v[i]],w[i]);
    }
    prim(n);
    for(int i=1;i<=q;i++) {
        int x,y;scanf("%d%d",&x,&y);
        puts(y<=dp[u[x]][v[x]]?"Yes":"No");
    }
    return 0;
}