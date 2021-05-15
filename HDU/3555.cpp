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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
LL dp[20][11];
VI lim;
LL dfs(int x,int d,bool a,bool b) {
    if(!x) return !a;
    if(!a&&!b&&dp[x][d]!=-1) return dp[x][d];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        if(d==4&&i==9) continue;
        ret+=dfs(x-1,i,a&(!i),b&(i==mx));
    }
    if(!a&&!b) dp[x][d]=ret;
    return ret;
}
LL solve(LL x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,0,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    memset(dp,-1,sizeof dp);
    while(tt--) {
        LL n;
        scanf("%lld",&n);
        printf("%lld\n",n-solve(n));
    }
    return 0;
}