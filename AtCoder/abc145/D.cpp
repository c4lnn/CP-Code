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
const LL MOD=1e9+7;
const int N=1e6+5;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int b=2*n-m;
    if(b%3||b<0) return cout<<0<<'\n',0;
    b/=3;
    int a=n-2*b;
    if(a<0) return cout<<0<<'\n',0;
    LL aa=1,bb=1,cc=1;
    for(int i=1;i<=a+b;i++) {
        cc=cc*i%MOD;
        if(i==a) aa=cc;
        if(i==b) bb=cc;
    }
    cout<<cc*qpow(aa,MOD-2)%MOD*qpow(bb,MOD-2)%MOD<<'\n';
    return 0;
}