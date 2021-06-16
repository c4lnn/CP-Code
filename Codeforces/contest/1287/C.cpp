#include<bits/stdc++.h>

using namespace std;
const int N=105;
int n;
int a[N];
int dp[N][N][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof dp);
    if(n>1&&(a[1]==0||a[1]%2==0)) dp[1][n/2-1][0]=0;
    if(a[1]==0||a[1]%2==1) dp[1][n/2][1]=0;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=n/2;j++)
            for(int k=0;k<2;k++)
            {
                if(j>0&&(a[i]==0||a[i]%2==0)) dp[i][j-1][0]=min(dp[i][j-1][0],dp[i-1][j][k]+(k==1));
                if(i+j-1<n&&(a[i]==0||a[i]%2==1)) dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][k]+(k==0));
            }
    cout<<min(dp[n][0][0],dp[n][0][1])<<endl;
    return 0;
}