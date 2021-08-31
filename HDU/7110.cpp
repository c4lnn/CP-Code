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
const int N=205;
int f[N][N],g[N][N],sum[N][N][2],dp[N][N][2],cnt[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m,w;cin>>n>>m>>w;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                char c;
                cin>>f[i][j]>>c;
                g[i][j]=c=='Y';
            }
        }
        for(int j=1;j<=m;j++) {
            cnt[j]=0;
            sum[j][0][0]=sum[j][0][1]=0;
            for(int i=n;i>=1;i--) {
                if(g[i][j]) sum[j][cnt[j]][0]+=f[i][j];
                else {
                    ++cnt[j];
                    sum[j][cnt[j]][0]=sum[j][cnt[j]-1][0]+f[i][j];
                    sum[j][cnt[j]][1]=sum[j][cnt[j]-1][0]+f[i][j];
                }
            }
        }
        memset(dp,0xc0,sizeof dp);
        dp[0][0][0]=0;
        int res=0;
        for(int i=1;i<=m;i++) {
            for(int j=0;j<=w;j++) {
                for(int k=0;k<=cnt[i]&&k<=j;k++) {
                    if(w-j) dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][0]+sum[i][k][0]);
                    if(k) dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][0]+sum[i][k][1]);
                    if(j-k) dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][1]+sum[i][k][0]);
                }
                if(i==m) res=max({res,dp[i][j][0],dp[i][j][1]});
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}