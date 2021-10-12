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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const LL MOD=1e9+7;
const int N=4e5+5;
LL fac[N],invfac[N],power[N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
void init(int n) {
    fac[0]=power[0]=1;
    for(int i=1;i<=n;i++) {
        fac[i]=fac[i-1]*i%MOD;
        power[i]=power[i-1]*2%MOD;
    }
    invfac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
}
LL binom(int n,int m) {
    return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(4e5);
    int n,m,q;cin>>n>>m>>q;
    while(q--) {
        int a,b;cin>>a>>b;
        if(a==n&&b==m) cout<<0<<'\n';
        else if(a==n) cout<<binom(a+b-1,a-1)*power[m-b]%MOD<<'\n';
        else cout<<binom(a+b-1,b-1)*power[n-a]%MOD<<'\n';
    }
    return 0;
}