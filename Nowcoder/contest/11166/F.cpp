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
const int N=20;
LL dp[N][2][2][2];
VI lim;
LL dfs(int x,int f1,int f2,int f3,bool a,bool b) {
    if(!x) return f1;
    if(!a&&!b&&dp[x][f1][f2][f3]!=-1) return dp[x][f1][f2][f3];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        int t=i%3;
        int ff1=0,ff2=0,ff3=0;
        if(!(a&(!i))) {
            if(t==0) {
                ff1=1;
                if(f2) ff2=1;
                if(f3) ff3=1;
            }
            else if(t==1) {
                ff2=1;
                if(f3) ff1=1;
                if(f2) ff3=1;
            }
            else if(t==2) {
                ff3=1;
                if(f2) ff1=1;
                if(f3) ff2=1;
            }
        }
        ret+=dfs(x-1,f1|ff1,f2|ff2,f3|ff3,a&(!i),b&(i==mx));
    }
    if(!a&&!b) dp[x][f1][f2][f3]=ret;
    return ret;
}
LL solve(LL x) {
    lim.clear();
    lim.PB(0);
    while(x) {
        lim.PB(x%10);
        x/=10;
    }
    return dfs(SZ(lim)-1,0,0,0,true,true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof dp);
    int T;cin>>T;
    while(T--) {
        LL l,r;cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<'\n';
    }
    return 0;
}