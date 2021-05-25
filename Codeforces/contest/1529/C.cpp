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
const int N=1e5+5;
int l[N],r[N];
LL dp[N][2];
VI g[N];
void dfs(int u,int fa) {
    for(auto v:g[u]) if(v!=fa) {
        dfs(v,u);
        dp[u][0]+=max(dp[v][0]+abs(l[u]-l[v]),dp[v][1]+abs(l[u]-r[v]));
        dp[u][1]+=max(dp[v][0]+abs(r[u]-l[v]),dp[v][1]+abs(r[u]-r[v]));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=0,g[i].clear();
        for(int i=1;i<=n;i++) {
            cin>>l[i]>>r[i];
        }
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v),g[v].PB(u);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
    return 0;
}