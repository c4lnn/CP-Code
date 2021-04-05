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
LL dp[20][165][165];
VI lim;
LL dfs(int x,int sum,int mod,bool a,bool b,int d) {
    if(!x) return (sum==d)&(!mod);
    if(!a&&!b&&dp[x][sum][mod]!=-1) return dp[x][sum][mod];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        if(sum+i>d) break;
        ret+=dfs(x-1,sum+i,(mod*10+i)%d,a&(!i),b&(i==mx),d);
    }
    if(!a&&!b) dp[x][sum][mod]=ret;
    return ret;
}
LL solve(LL x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    LL ret=0;
    for(int i=1;i<=SZ(lim)*9-9;i++) {
        memset(dp,-1,sizeof dp);
        ret+=dfs(SZ(lim)-1,0,0,true,true,i);
    }
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    LL a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",solve(b)-solve(a-1));
    return 0;
}