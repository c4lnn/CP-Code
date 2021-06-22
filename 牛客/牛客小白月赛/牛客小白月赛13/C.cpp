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
const int N=35;
int n;
LL dp[N][N<<2];
LL fpow(LL a,int b) {
    LL ret=1;
    while(b) {
        if(b&1) ret*=a;
        a*=a;
        b>>=1;
    }
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;
    for(int i=2;i<=n;i++)
        for(int j=i;j<=i*4;j++)
            for(int k=1;k<=4;k++)
                if(j-k)
                    dp[i][j]+=dp[i-1][j-k];
    LL a=0,b=fpow(4,n);
    for(int i=1;i<n*3;i++) a+=dp[n][i];
    a=b-a;
    LL gcd=__gcd(a,b);
    printf("%lld/%lld\n",a/gcd,b/gcd);
    return 0;
}