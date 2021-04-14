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
const LL MOD=2520;
LL dp[48][20][2520];
VI lim,d;
void init() {
    for(int i=2;i<1<<10;i++) {
        int t=1;
        for(int j=1;j<10;j++) {
            if(i&(1<<j)) {
                t=t*j/__gcd(t,j);
            }
        }
        d.PB(t);
    }
    sort(ALL(d));
    d.resize(unique(ALL(d))-d.begin());
    memset(dp,-1,sizeof dp);
}
LL dfs(int x,int mod,int st,bool a,bool b) {
    if(!x) return !a&&!(mod%st);
    int t=lower_bound(ALL(d),st)-d.begin();
    if(!a&&!b&&dp[t][x][mod]!=-1) return dp[t][x][mod];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) ret+=dfs(x-1,(mod*10+i)%MOD,a?i:(i>1?st*i/__gcd(st,i):st),a&(!i),b&(i==mx));
    if(!a&&!b) dp[t][x][mod]=ret;
    return ret;
}
LL solve(LL x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    LL ret=0;
    return dfs(SZ(lim)-1,0,0,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    init();
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        LL l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
    return 0;
}