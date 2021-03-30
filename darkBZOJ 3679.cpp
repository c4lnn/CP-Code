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
LL n,l,r,dp[20][6000];
vector<int> lim;
vector<LL> c;
void get(int x,int pre,LL prod) {
    if(x==19) {c.PB(prod);return;}
    for(int i=pre;i<=9;i++) {
        if(prod*i>1000000000ll) break;
        get(x+1,i,prod*i);
    }
}
LL dfs(int x,int prod,bool a,bool b) {
    if(!x) return prod!=-1;
    if(!a&&!b&&dp[x][prod]!=-1) return dp[x][prod];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        int t=max(prod,0);
        if(c[t]*i>n) break;
        if(a&&!i) ret+=dfs(x-1,-1,true,b&(i==mx));
        else if(i) ret+=dfs(x-1,lower_bound(ALL(c),c[t]*i)-c.begin(),false,b&(i==mx));
    }
    if(!a&&!b) dp[x][prod]=ret;
    return ret;
}
LL solve(LL x) {
    memset(dp,-1,sizeof dp);
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,-1,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    get(1,1,1ll);
    sort(ALL(c));
    c.resize(unique(ALL(c))-c.begin());
    scanf("%lld%lld%lld",&n,&l,&r);
    printf("%lld\n",solve(r-1)-solve(l-1));
    return 0;
}