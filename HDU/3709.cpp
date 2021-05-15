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
LL dp[20][20][2000];
VI lim;
LL dfs(int x,int st,bool a,bool b,int k) {
    if(!x) return a?k==1:!st;
    if(!a&&!b&dp[k][x][st]!=-1) return dp[k][x][st];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=0;i<=mx;i++) {
        if(x<k&&st-i*(k-x)<0) break;
        if(x<k) ret+=dfs(x-1,st-i*(k-x),a&(!i),b&(i==mx),k);
        else ret+=dfs(x-1,st+i*(x-k),a&(!i),b&(i==mx),k);
    }
    if(!a&&!b) dp[k][x][st]=ret;
    return ret;
}
LL solve(LL x) {
    if(x==-1) return 0;
    lim.clear();
    lim.PB(-1);
    if(!x) lim.PB(0);
    while(x) lim.PB(x%10),x/=10;
    LL ret=0;
    for(int i=1;i<SZ(lim);i++) ret+=dfs(SZ(lim)-1,0,true,true,i);
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    int tt;
    cin>>tt;
    while(tt--) {
        LL l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<"\n";
    }
    return 0;
}