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
const int N=305;
LL h[N],dp[N][N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>h[i];
    memset(dp,0x3f,sizeof dp);
    dp[1][0][0]=h[1];
    dp[0][0][0]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=m;j++) {
            if(j>i) break;
            // change
            if(j) dp[i][j][1]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]);
            // not change
            // k+1,k+2,...,i-1
            for(int k=max(0,i-j-1);k<=i-1;k++) dp[i][j][0]=min(dp[i][j][0],dp[k][j-(i-1-k)][0]+max(0ll,h[i]-h[k]));
        }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=min(i,m);j++) {
            cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<'\n';
        }
    }
    LL mn=LLONG_MAX;
    for(int i=0;i<=m;i++) mn=min({mn,dp[n][i][0],dp[n][i][1]});
    cout<<mn<<'\n';
    return 0;
}