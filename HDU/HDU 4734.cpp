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
int k,dp[11][5000];
VI lim;
int f(int x) {
    int ret=0,t=0;
    while(x) ret+=x%10*(1<<(t++)),x/=10;
    return ret;
}
int dfs(int x,int sum,bool b) {
    if(!x) return 1;
    if(!b&&dp[x][sum]!=-1) return dp[x][sum];
    int mx=b?lim[x]:9;
    int ret=0;
    for(int i=0;i<=mx;i++) {
        if(sum-i*(1<<(x-1))<0) break;
        ret+=dfs(x-1,sum-i*(1<<(x-1)),b&i==mx);
    }
    if(!b) dp[x][sum]=ret;
    return ret;
}
int solve(int x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,k,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof dp);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++) {
        int n;
        cin>>k>>n;
        k=f(k);
        cout<<"Case #"<<cas<<": "<<solve(n)<<'\n';
    }
    return 0;
}