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
LL qmul(LL a,LL b,LL m) { // b >= 0
    LL ret=0;
    while(b) {
        if(b&1) ret=(ret+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ret;
}
LL qpow(LL a,LL b,LL m) {
    LL ret=1;
    while(b) {
        if(b&1) ret=qmul(ret,a,m);
        a=qmul(a,a,m);
        b>>=1;
    }
    return ret;
}
bool check(LL a,LL n) {
    if(n==2) return true;
    if(n==1||!(n&1)) return false;
    LL d=n-1;
    while(!(d&1)) d>>=1;
    LL t=qpow(a,d,n);
    while(d!=n-1&&t!=1&&t!=n-1) {
        t=qmul(t,t,n);
        d<<=1;
    }
    return t==n-1||d&1;
}
bool miller_rabin(LL n) {
    static vector<LL> P={2,325,9375,28178,450775,9780504,1795265022};
    if(n<=1) return false;
    for(LL x:P) {
        if(x>n) break;
        if(!check(x,n)) return false;
    }
    return true;
}
mt19937 mt(time(0));
LL pollard_rho(LL n,LL c) {
    LL x=uniform_int_distribution<LL>(1,n-1)(mt),y=x;
    auto f=[&](LL v) {
        LL t=qmul(v,v,n)+c;
        return t<n?t:t-n;
    };
    while(1) {
        x=f(x),y=f(f(y));
        if(x==y) return n;
        LL d=__gcd(abs(x-y),n);
        if(d!=1) return d;
    }
}
VI fac; // 无序，有重复质因数
void get_fac(LL n,LL cc=19260817) {
    if(n==4) {fac.PB(2),fac.PB(2);return;}
    if(miller_rabin(n)) {fac.PB(n);return;}
    LL p=n;
    while(p==n) p=pollard_rho(n,--cc);
    get_fac(p),get_fac(n/p);
}
bool go_fac(LL n) {
    fac.clear();
    if(n<=1) return false;
    get_fac(n);
    int sz=SZ(fac);
    sort(ALL(fac));
    fac.resize(unique(ALL(fac))-fac.begin());
    return SZ(fac)<sz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        LL n;cin>>n;
        cout<<(go_fac(n)?"yes":"no")<<'\n';
    }
    return 0;
}