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
int dp[11][15][10][2];
VI lim;
int dfs(int x,int mod,int d,int f,bool a,bool b) {
    if(!x) return (!a)&(!mod)&(f);
    if(!a&&!b&&dp[x][mod][d][f]!=-1) return dp[x][mod][d][f];
    int mx=b?lim[x]:9;
    int ret=0;
    for(int i=0;i<=mx;i++) ret+=dfs(x-1,(mod*10+i)%13,i,f|((d==1)&(i==3)),a&(!i),b&(i==mx));
    if(!a&&!b) dp[x][mod][d][f]=ret;
    return ret;
}
int solve(int x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,0,0,0,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    int n;
    while(~scanf("%d",&n)) printf("%d\n",solve(n));
    return 0;
}