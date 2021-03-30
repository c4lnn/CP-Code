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
const LL MOD=1e9+7;
LL dp[105][10][3];
VI lim;
LL dfs(int x,int d,int f,bool a,bool b) {
    if(!x) return !a;
    if(!a&&!b&&dp[x][d][f]!=-1) return dp[x][d][f];
    int mx=b?lim[x]:9;
    LL ret=0;
    for(int i=f==1?d:0;i<=mx;i++) {
        if(a||f==0&&i<d) ret=(ret+dfs(x-1,i,0,a&(!i),b&(i==mx)))%MOD;
        else if(i>d) ret=(ret+dfs(x-1,i,1,a&(!i),b&(i==mx)))%MOD;
        else ret=(ret+dfs(x-1,d,f,a&(!i),b&(i==mx)))%MOD;
    }
    if(!a&&!b) dp[x][d][f]=ret;
    return ret;
}
LL solve(const string &s) {
    lim.clear();
    lim.PB(-1);
    for(int i=SZ(s)-1;i>=0;i--) lim.PB(s[i]-'0');
    return dfs(SZ(lim)-1,0,-1,true,true);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    memset(dp,-1,sizeof dp);
    while(tt--) {
        string s;
        cin>>s;
        printf("%lld\n",solve(s));
    }
    return 0;
}