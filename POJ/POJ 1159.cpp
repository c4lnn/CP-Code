#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=5e3+5;
char s[N];
int n,dp[2][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n) {
        cin>>s+1;
        memset(dp,0,sizeof dp);
        for(int j=1;j<n;j++) {
            for(int i=1;i+j<=n;i++) {
                if(s[i]==s[i+j]) dp[j&1][i]=dp[j&1][i+1];
                else dp[j&1][i]=min(dp[(j-1)&1][i],dp[(j-1)&1][i+1])+1;
            }
        }
        cout<<dp[(n-1)&1][1]<<'\n';
    }
    return 0;
}