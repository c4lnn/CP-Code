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
const int N=2e6+5;
LL f[N],g[N],h[N],sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=0;i<1<<n;i++) cin>>f[i];
    for(int i=0;i<1<<n;i++) cin>>g[i];
    for(int i=0;i<1<<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<1<<n;j++) if(j&(1<<i)) {
            f[j]=(f[j]+f[j^(1<<i)])%MOD;
            g[j]=(g[j]+g[j^(1<<i)])%MOD;
            h[j]=(h[j]+h[j^(1<<i)])%MOD;
        }
    }
    for(int i=0;i<1<<n;i++) sum[i]=f[i]*g[i]%MOD*h[i]%MOD;
    for(int i=n-1;~i;i--) {
        for(int j=0;j<1<<n;j++) if(j&(1<<i)) {
            sum[j]=(sum[j]+MOD-sum[j^(1<<i)])%MOD;
        }
    }
    LL res=0;
    for(int i=0;i<1<<n;i++) res=(res+sum[i]*(1<<__builtin_popcount(i))%MOD)%MOD;
    cout<<res<<'\n';
    return 0;
}