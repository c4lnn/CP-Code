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
const int N=1e3+5;
int a[N][N];
LL dp[N][N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    LL res=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(j>1) dp[i][j][0]=dp[i][j-1][1]+(a[i][j]^a[i][j-1])+__builtin_popcount(a[i][j]^a[i][j-1]); // l
            dp[i][j][1]=max(dp[i][j-1][0],dp[i][j-1][1]); // r
        }
        res+=max(dp[i][m][0],dp[i][m][1]);
    }
    memset(dp,0,sizeof dp);
    for(int j=1;j<=m;j++) {
        for(int i=1;i<=n;i++) {
            if(i>1) dp[i][j][0]=dp[i-1][j][1]+(a[i][j]^a[i-1][j])+__builtin_popcount(a[i][j]^a[i-1][j]); // u
            dp[i][j][1]=max(dp[i-1][j][0],dp[i-1][j][1]); // d
        }
        res+=max(dp[n][j][0],dp[n][j][1]);
    }
    cout<<res<<'\n';
    return 0;
}