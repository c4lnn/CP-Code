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
const int N=2005;
int n,k,a[N],b[N],dp[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    for(int cs=1;cs<=n;cs++) {
        scanf("%d",&k);
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        for(int i=2;i<=k;i++) scanf("%d",&b[i]);
        for(int i=1;i<=k;i++) dp[i]=0x3f3f3f3f;
        for(int i=1;i<=k;i++) {
            dp[i]=dp[i-1]+a[i];
            if(i>=2) dp[i]=min(dp[i],dp[i-2]+b[i]);
        }
        int h=8+dp[k]/3600;
        bool f=false;
        if(h>=12) h-=12,f=true;
        dp[k]%=3600;
        int m=dp[k]/60;
        printf("%02d:%02d:%02d ",h,m,dp[k]%60);
        puts(f?"pm":"am");
    }
    return 0;
}