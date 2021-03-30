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
int dp[11][14];
VI lim;
int dfs(int x,int d,bool a,bool b) {
    if(!x) return 1;
    if(!a&&!b&&dp[x][d]!=-1) return dp[x][d];
    int mx=b?lim[x]:9,ret=0;
    for(int i=0;i<=mx;i++) {
        if(abs(d-i)<2) continue;
        if(a&(!i)) ret+=dfs(x-1,11,true,b&(i==mx));
        else ret+=dfs(x-1,i,false,b&(i==mx));
    }
    if(!a&&!b) dp[x][d]=ret;
    return ret;
}
int solve(int x) {
    memset(dp,-1,sizeof dp);
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,11,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",solve(b)-solve(a-1));
    return 0;
}