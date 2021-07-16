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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const LL MOD=998244353;
const int N=1e6+5;
LL fac[N],invfac[N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
void init_invfac(int n) {
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    invfac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
}
LL C(int a,int b) {
    return fac[a]*invfac[b]%MOD*invfac[a-b]%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    init_invfac(n+m);
    LL res=0;
    for(int i=0;i<n;i++) res=(res+(n-i)*i%MOD*C(i+m-2,m-2)%MOD)%MOD;
    cout<<res<<'\n';
    return 0;
}