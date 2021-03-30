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
const int N=105;
const int DIR[4][2]={-1,0,1,0,0,-1,0,1};
int n,m,a[N][N],dp[N][N];
bool valid(int x,int y) {
    if(x>=1&&x<=n&&y>=1&&y<=n) return true;
    return false;
}
int dfs(int x,int y) {
    if(dp[x][y]) return dp[x][y];
    dp[x][y]=a[x][y];
    for(int i=1;i<=m;i++)
        for(int j=0;j<4;j++) {
            int tx=x+DIR[j][0]*i,ty=y+DIR[j][1]*i;
            if(!valid(tx,ty)||a[tx][ty]<=a[x][y]) continue;
            dp[x][y]=max(dp[x][y],dfs(tx,ty)+a[x][y]);
        }
    return dp[x][y];
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(n==-1&&m==-1) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof dp);
        dfs(1,1);
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                res=max(res,dp[i][j]);
        printf("%d\n",res);
    }
    return 0;
}