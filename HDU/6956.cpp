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
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
LL BSGS(LL a,LL b,LL m) {
    a%=m,b%=m;
    if(!a&&!b) return 1;
    if(!a) return -1;
    static unordered_map<LL,LL> mp;
    mp.clear();
    LL r=sqrt(m+1.5),v=1;
    for(int i=1;i<=r;i++) {
        v=v*a%m;
        mp[b*v%m]=i;
    }
    LL vv=v;
    for(int i=1;i<=r;i++) {
        auto it=mp.find(vv);
        if(it!=mp.end()) return i*r-it->second;
        vv=vv*v%m;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        LL n,x;cin>>n>>x;
        LL odd=BSGS(n-1,(n*x+n-1)%MOD,MOD);
        if(odd!=-1&&odd%2==0) odd=-1;
        LL even=BSGS(n-1,((n*x-n+1)%MOD+MOD)%MOD,MOD);
        if(even!=-1&&even%2==1) even=-1;
        if(odd==-1&&even==-1) cout<<-1<<'\n';
        else if(odd==-1||even==-1) cout<<max(odd,even)<<'\n';
        else cout<<min(odd,even)<<'\n';
    }
    return 0;
}