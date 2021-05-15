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
const int N=1e5+5;
int n,dp[2][15],cnt[N][15];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d",&n)&&n) {
        int t=0;
        memset(cnt,0,sizeof cnt);
        for(int i=1;i<=n;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            t=max(t,b);
            cnt[b][a]++;
        }
        memset(dp,0,sizeof dp);
        int res=0;
        for(int i=1;i<=t;i++)
            for(int j=max(0,5-i);j<=min(10,5+i);j++) {
                dp[i&1][j]=max({dp[!(i&1)][j-1],dp[!(i&1)][j],dp[!(i&1)][j+1]})+cnt[i][j];
                res=max(res,dp[i&1][j]);
            }
        printf("%d\n",res);
    }
    return 0;
}