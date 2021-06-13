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
int mn[N],phi[N];
LL h[N],s[N],inv[10];
unordered_map<int,LL> _s;
VI p;
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
    phi[1]=h[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,phi[i]=i-1,h[i]=(i*i%MOD-1+MOD)%MOD,p.PB(i);
        for(auto x:p) {
            if(x*i>n) break;
            mn[x*i]=x;
            phi[x*i]=x%i?phi[i]*(x-1):phi[i]*x;
            h[x*i]=x%i?h[i]*h[x]%MOD:h[i]*x%MOD*x%MOD;
            if(x%i==0) break;
        }
    }
    for(int i=1;i<=n;i++) s[i]=s[i-1]+h[i]-3*phi[i]+2*(i==1);
}
LL calc(int n) {
    if(n<=1e6) return s[n];
    if(_s.count(n)) return _s[n];
    _s[n]=n*(n-1)%MOD*(n-2)%MOD*inv[3]%MOD;
    for(int l=2,r;l<=n;l=r+1) {
        r=n/(n/l);
        _s[n]=((_s[n]-(r-l+1)*calc(n/l)%MOD)%MOD+MOD)%MOD;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    inv[3]=qpow(3,MOD-2);
    init(1e6);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        cout<<calc(n)<<'\n';
    }
    return 0;
}