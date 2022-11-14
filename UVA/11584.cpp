#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
//head
const int N=1e3+5;
char s[N];
bool f[N][N];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>s+1;
        int L=strlen(s+1);
        memset(f,false,sizeof f);
        for(int len=1;len<=L;len++)
            for(int l=1;l+len-1<=L;l++) {
                int r=l+len-1;
                if(len==1||(l+1==r||f[l+1][r-1])&&s[l]==s[r]) f[l][r]=true;
            }
        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        for(int i=1;i<=L;i++)
            for(int j=1;j<=i;j++)
                if(f[j][i])
                    dp[i]=min(dp[i],dp[j-1]+1);
        cout<<dp[L]<<endl;
    }
    return 0;
}