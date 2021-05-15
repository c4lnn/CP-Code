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
const int N=105;
int n,m,dist[N];
LL dp1[N],dp2[N];
VI g[N];
void bfs1() {
    queue<int> q;
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f;
    q.push(1);
    dist[1]=0;
    dp1[1]=1;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(dist[v]>dist[u]+1) {
                dist[v]=dist[u]+1;
                dp1[v]=dp1[u];
                q.push(v);
            }
            else if(dist[v]==dist[u]+1) {
                dp1[v]+=dp1[u];
            }
        }
    }
}
void bfs2(int f) {
    queue<int> q;
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f,dp2[i]=0;
    q.push(1);
    dist[1]=0;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(dist[v]>dist[u]+1) {
                dist[v]=dist[u]+1;
                if(u==f) dp2[v]=dp1[u];
                else dp2[v]=dp2[u];
                q.push(v);
            }
            else if(dist[v]==dist[u]+1) {
                if(u==f) dp2[v]+=dp1[u];
                else dp2[v]+=dp2[u];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    bfs1();
    LL mx=dp1[n];
    for(int i=2;i<n;i++) {
        bfs2(i);
        mx=max(mx,dp2[n]*2);
    }
    cout<<fixed<<setprecision(12)<<1.0*mx/dp1[n]<<'\n';
    return 0;
}