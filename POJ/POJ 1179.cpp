#include<iostream>
#include<vector>

using namespace std;

const int N=105;

int n;
int a[N];
char opt[N];
int dp[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>opt[i];
        cin>>a[i];
        opt[i+n]=opt[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n+n;i++) dp[i][i][0]=dp[i][i][1]=a[i];
    for(int len=2;len<=n;len++) {
        for(int l=1;l+len-1<=n+n;l++) {
            int r=l+len-1;
            dp[l][r][0]=0xc0c0c0c0,dp[l][r][1]=0x3f3f3f3f;
            for(int k=l;k<r;k++) {
                if(opt[k+1]=='t') {
                    dp[l][r][0]=max(dp[l][r][0],dp[l][k][0]+dp[k+1][r][0]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][1]+dp[k+1][r][1]);
                }
                else {
                    dp[l][r][0]=max(dp[l][r][0],max(dp[l][k][0]*dp[k+1][r][0],dp[l][k][1]*dp[k+1][r][1]));
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][0]*dp[k+1][r][0]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][0]*dp[k+1][r][1]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][1]*dp[k+1][r][0]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][1]*dp[k+1][r][1]);
                }
            }
        }
    }
    int max_res=0x80000000;
    vector<int>res;
    for(int l=1;l<=n;l++) {
        if(dp[l][l+n-1][0]>max_res) {
            max_res=dp[l][l+n-1][0];
            res.clear();
            res.push_back((l-1)%n);
        }
        else if(dp[l][l+n-1][0]==max_res) res.push_back((l-1)%n);
    }
    cout<<max_res<<endl;
    for(int i=0;i<res.size();i++) cout<<res[i]+1<<" ";
    cout<<endl;
    return 0;
}