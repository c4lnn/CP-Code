#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
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
const int N=2e3+5;
int w[N],dp[N];
VPII g[N];
int dfs(int u) {
    if(dp[u]!=0x3f3f3f3f) return dp[u];
    for(int i=0;i<SZ(g[u]);i++) {
        dp[u]=min(dp[u],max(dfs(g[u][i].FI),dfs(g[u][i].SE))+max(w[g[u][i].FI],w[g[u][i].SE]));
    }
    return dp[u];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,t;cin>>n>>m>>k>>t;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) dp[i]=0x3f3f3f3f;
    for(int i=1;i<=m;i++) {
        int x;
        cin>>x;
        dp[x]=0;
    }
    for(int i=1;i<=k;i++) {
        int a,b,c;cin>>a>>b>>c;
        g[c].PB(MP(a,b));
    }
    cout<<dfs(t)<<'\n';
    return 0;
}