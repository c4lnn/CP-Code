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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=40;
int c[N],w[N],b[N],dp[N][1<<20],cnt[N];
VI g[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    VI a;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        ++cnt[c[i]];
        if(cnt[c[i]]==2) {
            a.PB(c[i]);
            b[c[i]]=SZ(a)-1;
        }
    }
    for(int i=1;i<=n;i++) {
        cin>>w[i];
    }
    for(int i=1;i<=m;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v);
    }
    memset(dp,0xc0,sizeof dp);
    if(cnt[c[1]]==1) dp[1][0]=w[c[1]];
    else dp[1][1<<b[c[1]]]=w[c[1]];
    for(int u=1;u<n;u++) {
        for(int i=0;i<1<<SZ(a);i++) if(dp[u][i]>0) {
            for(auto v:g[u]) {
                if(cnt[c[v]]==1) dp[v][i]=max(dp[v][i],dp[u][i]+w[c[v]]);
                else {
                    if(i&(1<<b[c[v]])) dp[v][i]=max(dp[v][i],dp[u][i]);
                    else dp[v][i|(1<<b[c[v]])]=max(dp[v][i|(1<<b[c[v]])],dp[u][i]+w[c[v]]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        int mx=0;
        for(int j=0;j<1<<SZ(a);j++) {
            mx=max(mx,dp[i][j]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}