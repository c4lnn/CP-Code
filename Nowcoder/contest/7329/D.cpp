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
const int N=5005;
const LL MOD=998244353;
int n,d,a[N];
LL fac[N],invf[N],dp[2][N][2];
LL fpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    dp[1][1][1]=dp[1][0][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=i;j++) {
            dp[i&1][j][0]=(dp[(i-1)&1][j][0]+dp[(i-1)&1][j][1]*(a[i-1]+d<=a[i]))%MOD;
            if(j>=1) dp[i&1][j][1]=(dp[(i-1)&1][j-1][0]+dp[(i-1)&1][j-1][1])%MOD;
        }
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    invf[n]=fpow(fac[n],MOD-2);
    for(int i=n-1;i>=1;i--) invf[i]=invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=n;i++) printf("%lld\n",(dp[n&1][i][0]+dp[n&1][i][1])%MOD*fac[i]%MOD*fac[n-i]%MOD*invf[n]%MOD);
    return 0;
}