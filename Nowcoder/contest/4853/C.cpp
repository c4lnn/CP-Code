#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const ll mod=1e9+7;
const int N=1010;
char s[N];
ll dp[N][N];
int pre[30];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    cin>>s+1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i][0]=1;
        for(int j=1;j<=min(i,k);j++) {
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
            if(pre[s[i]-'a']) dp[i][j]=(dp[i][j]+mod-dp[pre[s[i]-'a']-1][j-1])%mod;
        }
        pre[s[i]-'a']=i;
    }
    cout<<dp[n][k]<<endl;
    return 0;
}