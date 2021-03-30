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
LL fast_pow(LL n,int k,LL mod) {
    LL ret=1;
    while(k) {
        if(k&1) ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        LL n;
        int k;
        scanf("%lld%d",&n,&k);
        int len=k*log10(n);
        DB t=pow(10,k*log10(n)-(len-1));
        while(t<100) t*=10;
        printf("Case %d: %d %03lld\n",cs,(int)t,fast_pow(n%1000,k,1000ll));
    }
    return 0;
}