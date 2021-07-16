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
const int N=1e8+5;
LL mn[N];
vector<LL> p;
void get_prime(LL n) {
    for(LL i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.push_back(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
}
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
    LL n;
    cin>>n;
    if(n<=5) cout<<"empty"<<'\n';
    else {
        get_prime(n/2);
        LL res=1;
        for(auto x:p) {
            LL t=(LL)(log(n)/log(x));
            if(x==2) --t;
            if(x==2&&qpow(x,t)*3>n) --t;
            else if(x!=2&&qpow(x,t)*2>n) --t;
            res=res*qpow(x,t)%MOD;
        }
        cout<<res<<'\n';
    }
    return 0;
}