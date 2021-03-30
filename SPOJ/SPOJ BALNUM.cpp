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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
ULL dp[25][60000];
VI lim;
int update(int st,int x) {
    int t=st,power=1;
    for(int i=0;i<x;i++) t/=3,power*=3;
    if(t%3<=1) st+=power;
    else if(t%3==2) st-=power;
    return st;
}
bool judge(int st) {
    for(int i=0;i<=9;i++) {
        if((i&1)&&st%3==1) return false;
        if(!(i&1)&&st%3==2) return false;
        st/=3;
    }
    return true;
}
ULL dfs(int x,int st,bool a,bool b) {
    if(!x) return !a&judge(st);
    if(!b&&dp[x][st]!=-1) return dp[x][st];
    int mx=b?lim[x]:9;
    ULL ret=0;
    for(int i=0;i<=mx;i++) ret+=dfs(x-1,(a&&!i)?0:update(st,i),a&(!i),b&(i==mx));
    if(!b) dp[x][st]=ret;
    return ret;
}
ULL solve(ULL x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,0,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof dp);
    int T;
    cin>>T;
    while(T--) {
        ULL l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<'\n';
    }
    return 0;
}