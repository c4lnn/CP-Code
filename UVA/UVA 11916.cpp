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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const LL MOD=1e8+7;
const int N=505;
int b,x[N],y[N];
LL n,k,r;
LL fast_pow(LL n,LL a) {
    LL ret=1;
    while(a) {
        if(a&1) ret=ret*n%MOD;
        n=n*n%MOD;
        a>>=1;
    }
    return ret;
}
LL BSGS(LL a,LL b,LL p) {
    a%=p,b%=p;
    if(!a&&!b) return 1;
    if(!a) return -1;
    static unordered_map<LL,LL> mp;
    mp.clear();
    LL m=sqrt(p+1.5),v=1;
    for(int i=1;i<=m;i++) {
        v=v*a%p;
        mp[b*v%p]=i;
    }
    LL vv=v;
    for(int i=1;i<=m;i++) {
        auto it=mp.find(vv);
        if(it!=mp.end()) return i*m-it->second;
        vv=vv*v%p;
    }
    return -1;
}
LL solve() {
    scanf("%lld%lld%d%lld",&n,&k,&b,&r);
    static map<PII,bool> mp;
    mp.clear();
    LL res=1;
    LL row=0,tot=0;
    for(int i=1;i<=b;i++) {
        scanf("%d%d",&x[i],&y[i]);
        mp[MP(x[i],y[i])]=true;
        if(x[i]==1) tot++;
        row=max(x[i]*1ll,row);
    }
    res=res*fast_pow(k,n-tot)%MOD;
    tot=n-tot;
    LL t=0;
    for(int i=1;i<=b;i++) {
        ++tot;
        if(x[i]==row) {++t;continue;}
        if(!mp.count(MP(x[i]+1,y[i]))) ++tot,res=res*k%MOD;
    }
    if(!row) row=1;
    res=res*fast_pow(k-1,n*row-tot)%MOD;
    if(res==r) return row;
    res=res*fast_pow(k,t)%MOD*fast_pow(k-1,n-t)%MOD;
    ++row;
    if(res==r) return row;
    return BSGS(fast_pow(k-1,n),fast_pow(res,MOD-2)*r%MOD,MOD)+row;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) printf("Case %d: %d\n",cs,solve());
    return 0;
}