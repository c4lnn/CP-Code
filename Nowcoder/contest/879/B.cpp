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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const LL MOD=998244353;
const int N=1e5+5;
LL n,k,p,fac[N],invfac[N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) (ret*=a)%=MOD;
        (a*=a)%=MOD;
        b>>=1;
    }
    return ret;
}
void init() {
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    invfac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
}
LL C(int a,int b) {
    return fac[b]*invfac[b-a]%MOD*invfac[a]%MOD;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>p;
    init();
    LL res=0;
    for(int i=n;i>=k;i--) (res+=C(i,n)*qpow(p,i)%MOD*qpow(1-p+MOD,n-i)%MOD)%=MOD;
    cout<<res<<'\n';
    return 0;
}
