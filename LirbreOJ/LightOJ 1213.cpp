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
const
LL fast_pow(LL n,LL k,LL mod) {
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
        LL n,k,mod;
        scanf("%lld%lld%lld",&n,&k,&mod);
        LL t=k*fast_pow(n,k-1,mod)%mod;
        LL res=0;
        for(int i=1;i<=n;i++) {
            LL x;
            scanf("%lld",&x);
            res=(res+x*t%mod)%mod;
        }
        printf("Case %d: %lld\n",cs,res);
    }
    return 0;
}