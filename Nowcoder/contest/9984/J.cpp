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
const int MOD=1e9+7;
const int N=1e4+5;
int n;
LL mn[N],cnt[N],a[N],b[N];
vector<LL> p;
void prime_seive(LL n) {
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
    prime_seive(10000);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    memset(cnt,0x3f,sizeof cnt);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<SZ(p);j++) {
            LL tot=0;
            if(a[i]%p[j]==0) while(a[i]%p[j]==0) ++tot,a[i]/=p[j];
            cnt[j]=min(cnt[j],tot*b[i]);
        }
    }
    LL res=1;
    for(int i=0;i<SZ(p);i++) res=res*qpow(p[i],cnt[i])%MOD;
    cout<<res<<'\n';
    return 0;
}