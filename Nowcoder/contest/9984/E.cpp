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
const LL HASH_MOD=998244353;
const LL HASH_BASE=131;
const int N=5e6+5;
LL power[N],ha[N],dp[N];
void init_power(int n) {
    power[0]=1;
    for(int i=1;i<=n;i++) power[i]=power[i-1]*HASH_BASE%HASH_MOD;
}
LL init_hash(const string &s) {
    LL ret=0;
    for(int i=0;i<SZ(s);i++) ret=(ret*HASH_BASE%HASH_MOD+s[i])%HASH_MOD;
    return ret;
}
LL get_hash(int l,int r) {
    return (ha[r]-ha[l-1]*power[r-l+1]%HASH_MOD+HASH_MOD)%HASH_MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string k;
    cin>>n>>k;
    init_power(5000000);
    for(int i=1;i<=SZ(k);i++) ha[i]=(ha[i-1]*HASH_BASE%HASH_MOD+k[i-1])%HASH_MOD;
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        int len=SZ(s);
        LL a=init_hash(s);
        for(int j=SZ(k);j>=len;j--) if(a==get_hash(j-len+1,j)) dp[j]+=dp[j-len];
    }
    cout<<dp[SZ(k)]<<'\n';
    return 0;
}