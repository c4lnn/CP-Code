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
const int N=2e5+5;
int n,m,c,mx,dist[N];
bool st[N];
VPII g[N];
int dijkstra() {
    for(int i=1;i<=mx;i++) dist[i]=0x3f3f3f3f,st[i]=false;
    priority_queue<PII,VPII,greater<PII>> q;
    q.emplace(0,1);
    dist[1]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.FI,w=x.SE;
            if(!st[v]&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                q.emplace(dist[v],v);
            }
        }
    }
    return dist[n]==0x3f3f3f3f?-1:dist[n];
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%d%d%d",&n,&m,&c);
        for(int i=1;i<=n;i++) {
            int x;
            scanf("%d",&x);
            g[n+x].EB(i,0);
            if(x>1) g[i].EB(n+x-1,c);
            if(x<n) g[i].EB(n+x+1,c);
            mx=max(mx,n+x);
        }
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].EB(v,w);
            g[v].EB(u,w);
        }
        printf("Case #%d: %d\n",cs,dijkstra());
        for(int i=1;i<=mx;i++) g[i].clear();
        mx=0;
    }
    return 0;
}