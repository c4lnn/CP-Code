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
const LL MOD=1e9+7;
const int N=705;
int nxt[N],stk[N],top;
LL dp[N][N][3][3];
LL dfs(int l,int r,int cl,int cr) {
    if(dp[l][r][cl][cr]!=-1) return dp[l][r][cl][cr];
    dp[l][r][cl][cr]=0;
    if(l+1==r) {
        if(cl==cr||cl+cr==3) return 0;
        return dp[l][r][cl][cr]=1;
    }
    if(nxt[l]==r) {
        if(cl==cr||cl+cr==3) return 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(cl&&i&&cl==i||j&&cr&&j==cr) continue;
                dp[l][r][cl][cr]=(dp[l][r][cl][cr]+dfs(l+1,r-1,i,j))%MOD;
            }
        }
        return dp[l][r][cl][cr];
    }
    dp[l][r][cl][cr]=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i&&j&&i==j) continue;
            dp[l][r][cl][cr]=(dp[l][r][cl][cr]+dfs(l,nxt[l],cl,i)*dfs(nxt[l]+1,r,j,cr))%MOD;
        }
    }
    return dp[l][r][cl][cr];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    int n=SZ(s);
    for(int i=n-1;~i;i--) {
        if(s[i]==')') stk[++top]=i;
        else nxt[i]=stk[top--];
    }
    memset(dp,-1,sizeof dp);
    LL res=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            res=(res+dfs(0,n-1,i,j))%MOD;
        }
    }
    cout<<res<<'\n';
    return 0;
}