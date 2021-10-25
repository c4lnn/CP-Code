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
VI lim1,lim2;
LL dp[31][2][2][2];
LL dfs(int x,bool a,bool b1,bool b2) {
    if(!x) return !a;
    if(dp[x][a][b1][b2]!=-1) return dp[x][a][b1][b2];
    int mx1=b1?lim1[x]:1;
    int mx2=b2?lim2[x]:1;
    LL ret=0;
    for(int i=0;i<=mx1;i++) {
        for(int j=0;j<=mx2;j++) if(i+j!=2) {
            if(a&&i+j>=1) ret=(ret+1ll*x*dfs(x-1,false,b1&(i==mx1),b2&(j==mx2)))%MOD;
            else ret=(ret+dfs(x-1,a,b1&(i==mx1),b2&(j==mx2)))%MOD;
        }
    }
    return dp[x][a][b1][b2]=ret;
}
LL solve(int x,int y) {
    memset(dp,-1,sizeof dp);
    lim1.clear();
    lim2.clear();
    lim1.PB(-1);
    lim2.PB(-1);
    while(x||y) {
        lim1.PB(x%2);
        lim2.PB(y%2);
        x/=2;
        y/=2;
    }
    return dfs(SZ(lim1)-1,true,true,true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int x,y;cin>>x>>y;
        cout<<solve(x,y)<<'\n';
    }
    return 0;
}