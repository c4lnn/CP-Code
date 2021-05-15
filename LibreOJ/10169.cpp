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
LL dp[14][14];
vector<LL> lim;
LL dfs(int x,LL sum,bool a,bool b,int d) {
    if(!x) return sum;
    if(!a&&!b&&dp[x][sum]!=-1) return dp[x][sum];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        if(a&&!i) ret+=dfs(x-1,sum+((x==1)&(!d)),a,b&(i==mx),d);
        else ret+=dfs(x-1,sum+(i==d),false,b&(i==mx),d);
    }
    if(!a&&!b) dp[x][sum]=ret;
    return ret;
}
LL solve(LL x,int d) {
    memset(dp,-1,sizeof dp);
    lim.clear();
    lim.PB(-1);
    if(!x) lim.PB(0);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,0,true,true,d);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    LL a,b;
    scanf("%lld%lld",&a,&b);
    for(int i=0;i<=9;i++) printf("%lld ",solve(b,i)-solve(a-1,i));
    puts("");
    return 0;
}