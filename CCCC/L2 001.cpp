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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=505;
int n,m,s,d,a[N],dist[N],dp[N],sum[N],pre[N];
VPII g[N];
bool st[N];
void dijkstra() {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f;
    priority_queue<PII,VPII,greater<PII>> q;
    q.emplace(0,s);
    dist[s]=0;
    dp[s]=1;
    sum[s]=a[s];
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.FI,w=x.SE;
            if(!st[v]) {
                if(dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    sum[v]=sum[u]+a[v];
                    pre[v]=u;
                    dp[v]=dp[u];
                    q.emplace(dist[v],v);
                }
                else if(dist[v]==dist[u]+w) {
                    if(sum[v]<sum[u]+a[v]) {
                        sum[v]=sum[u]+a[v];
                        pre[v]=u;
                    }
                    dp[v]+=dp[u];
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s>>d;
    ++s,++d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        int u,v,w;cin>>u>>v>>w;
        ++u,++v;
        g[u].EB(v,w),g[v].EB(u,w);
    }
    dijkstra();
    cout<<dp[d]<<' '<<sum[d]<<'\n';
    VI res;
    for(int i=d;i;i=pre[i]) res.PB(i-1);
    for(int i=SZ(res)-1;~i;i--) cout<<res[i]<<" \n"[i==0];
    return 0;
}