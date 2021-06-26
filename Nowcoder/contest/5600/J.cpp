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
int n;
LL cnt[100];
LL power(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        LL x;
        scanf("%lld",&x);
        for(int j=0;j<62;j++) if(x&(1ll<<j)) cnt[j]++;
    }
    LL res=0;
    int inv_2=power(2,MOD-2),inv_6=power(6,MOD-2);
    for(int i=0;i<62;i++) {
        if(cnt[i]>=1&&n-cnt[i]>=2) res=(res+(1ll<<i)%MOD*(n-cnt[i])%MOD*(n-cnt[i]-1)%MOD*cnt[i]%MOD*inv_2%MOD)%MOD;
        if(cnt[i]>=3) res=(res+(1ll<<i)%MOD*cnt[i]%MOD*(cnt[i]-1)%MOD*(cnt[i]-2)%MOD*inv_6%MOD)%MOD;
    }
    printf("%lld\n",res);
    return 0;
}