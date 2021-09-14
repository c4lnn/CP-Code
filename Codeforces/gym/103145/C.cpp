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
const LL MOD=998244353;
const int N=1e5+5;
LL dp[N][3];
VI g[N];
void dfs(int u,int fa) {
    dp[u][0]=dp[u][1]=dp[u][2]=1;
    for(auto v:g[u]) if(v!=fa) {
        dfs(v,u);
        dp[u][0]=dp[u][0]*(dp[v][0]+dp[v][2])%MOD;
        dp[u][1]=dp[u][1]*dp[v][0]%MOD;
        dp[u][2]=dp[u][2]*(dp[v][0]+dp[v][1]+dp[v][2])%MOD;
    }
    dp[u][2]=(dp[u][2]-dp[u][1]+MOD)%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v),g[v].PB(u);
        }
        dfs(1,0);
        cout<<(dp[1][0]+dp[1][2])%MOD<<'\n';
    }
    return 0;
}