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
//head
const LL MOD=1e9+7;
const int N=1e5+5;
LL n,m,k,fac[N],invfac[N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
void init() {
    fac[0]=1;
    for(int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%MOD;
    invfac[100000]=qpow(fac[100000],MOD-2);
    for(int i=99999;~i;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
}
LL C(LL a,LL b) {
    return fac[a]*invfac[b]%MOD*invfac[a-b]%MOD;
}
LL F(LL a,LL b) {
    return C(a+b-1,a);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    init();
    cin>>n>>m>>k;
    if(k&1) {
        LL res=0;
        if(n>=k/2&&m>=k/2+1) {
            LL t=1;
            if(n-k/2) t=F(n-k/2,k/2);
            if(m-k/2-1) t=t*F(m-k/2-1,k/2+1)%MOD;
            res+=t;
        }
        if(n>=k/2+1&&m>=k/2) {
            LL t=1;
            if(m-k/2) t=F(m-k/2,k/2);
            if(n-k/2-1) t=t*F(n-k/2-1,k/2+1)%MOD;
            res+=t;
        }
        cout<<res<<'\n';
    }
    else {
        if(n<k/2||m<k/2) cout<<0<<'\n';
        else {
            LL res=1;
            if(n-k/2) res=F(n-k/2,k/2);
            if(m-k/2) res=res*F(m-k/2,k/2)%MOD;
            cout<<res*2%MOD<<'\n';
        }
    }
    return 0;
}