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
const LL MOD=998244353;
const int N=20;
int popcount[1<<N];
LL inv[N*101],a[N][N],sum[N],res[N][N],dp[1<<N],s[N][1<<N];
VI b[N+1];
unordered_map<int,int> mp;
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
    int n;cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
            sum[i]+=a[i][j];
        }
    for(int i=1;i<=2000;i++) inv[i]=qpow(i,MOD-2);
    for(int i=0;i<n;i++) mp[1<<i]=i;
    for(int i=1;i<1<<n;i++) {
        popcount[i]=popcount[i&(i-1)]+1;
        b[popcount[i]].PB(i);
        for(int j=0;j<20;j++) s[j][i]=s[j][i&(i-1)]+a[j][mp[i&-i]];
    }
    b[0].PB(0);
    dp[0]=1;
    for(int i=0;i<n;i++)
        for(auto j:b[i])
            for(int k=0;k<n;k++) if(!((j>>k)&1)) {
                res[i][k]=(res[i][k]+dp[j]*a[i][k]%MOD*inv[sum[i]-s[i][j]]%MOD)%MOD;
                dp[j|(1<<k)]=(dp[j|(1<<k)]+dp[j]*a[i][k]%MOD*inv[sum[i]-s[i][j]]%MOD)%MOD;
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<res[i][j]<<" \n"[j==n-1];
    return 0;
}