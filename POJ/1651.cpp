#include <iostream>
#include <cstring>
using namespace std;
const int N=105;
int a[N],dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof dp);
    for(int i=2;i<n;i++) dp[i][i]=a[i]*a[i-1]*a[i+1];
    for(int len=2;len<n;len++) {
        for(int l=2;l+len-1<n;l++) {
            int r=l+len-1;
            dp[l][r]=min(a[l]*a[l-1]*a[r+1]+dp[l+1][r],a[r]*a[l-1]*a[r+1]+dp[l][r-1]);
            for(int k=l+1;k<r;k++) dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k+1][r]+a[k]*a[l-1]*a[r+1]);
        }
    }
    cout<<dp[2][n-1]<<'\n';
    return 0;
}