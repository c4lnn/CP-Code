#include <iostream>
#define SZ(x) (int)(x).size()
using namespace std;
const int N=105;
int dp[N][N];
int main() {
    string s;
    while(cin>>s) {
        if(s=="end") break;
        for(int len=2;len-1<SZ(s);len++)
            for(int l=0;l+len-1<SZ(s);l++) {
               int r=l+len-1;
               if(s[l]=='('&&s[r]==')'||s[l]=='['&&s[r]==']') dp[l][r]=dp[l+1][r-1]+2;
               else dp[l][r]=0;
               for(int k=l;k<r;k++) dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
           }
        cout<<dp[0][SZ(s)-1]<<'\n';
    }
    return 0;
}