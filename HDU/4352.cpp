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
int k;
LL dp[11][20][1100];
int cnt[1100],nxt[1100][10];
VI lim;
int update(int x,int s) {
    for(int i=s;i<10;i++) if(x&(1<<i)) return (x^(1<<i))|(1<<s);
    return x|(1<<s);
}
void init() {
    for(int i=0;i<1<<10;i++) {
        cnt[i]=__builtin_popcount(i);
        for(int j=0;j<10;j++) {
            nxt[i][j]=update(i,j);
        }
    }
}
LL dfs(int x,int st,bool a,bool b) {
    if(!x) return cnt[st]==k;
    if(!a&&!b&&dp[k][x][st]!=-1) return dp[k][x][st];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        if(cnt[nxt[st][i]]>k) break;
        ret+=dfs(x-1,(a&(!i))?0:nxt[st][i],a&(!i),b&(i==mx));
    }
    if(!a&&!b) dp[k][x][st]=ret;
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
    init();
    int tt;
    scanf("%d",&tt);
    LL l,r;
    memset(dp,-1,sizeof dp);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%lld%lld%d",&l,&r,&k);
        printf("Case #%d: %lld\n",cs,solve(r)-solve(l-1));
    }
    return 0;
}