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
LL dp[15][15];
VI lim;
LL dfs(int x,int d,bool a,bool b) {
    if(!x) return 1;
    if(!a&&!b&&dp[x][d]!=-1) return dp[x][d];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        if(i==4||d==6&&i==2) continue;
        ret+=dfs(x-1,i,a&(!i),b&(i==mx));
    }
    if(!a&&!b) dp[x][d]=ret;
    return ret;
}
LL solve(int x) {
    memset(dp,-1,sizeof dp);
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,0,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    LL a,b;
    while(~scanf("%lld%lld",&a,&b)) {
        if(!a&&!b) break;
        printf("%lld\n",solve(b)-solve(a-1));
    }
    return 0;
}