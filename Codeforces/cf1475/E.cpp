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
LL MOD=1e9+7;
const int N=1e3+5;
int n,k,a[N];
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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    fac[0]=1;
    for(int i=1;i<=1000;i++) fac[i]=fac[i-1]*i%MOD;
    invfac[1000]=qpow(fac[1000],MOD-2);
    for(int i=999;i>=0;i--) invfac[i]=invfac[i+1]*(i+1)%MOD;
    while(T--) {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        int t1=0,t2=0;
        for(int i=k;i>=1&&a[i]==a[k];i--) ++t1;
        for(int i=k+1;i<=n&&a[i]==a[k];i++) ++t2;
        t2+=t1;
        cout<<fac[t2]*invfac[t1]%MOD*invfac[t2-t1]%MOD<<'\n';
    }
    return 0;
}