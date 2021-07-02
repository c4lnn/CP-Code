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
const int N=16;
int p[N],cnt[1<<N],dp[1<<N];
bool st[1<<N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>p[i],sum+=p[i];
    sort(p+1,p+1+n,greater<int>());
    for(int i=1;i<=m;i++) {
        int x;cin>>x;
        int bit=0;
        for(int j=1;j<=x;j++) {
            int t;cin>>t;
            bit|=1<<t;
        }
        st[bit]=true;
    }
    for(int i=1;i<1<<n;i++) cnt[i]=cnt[i&(i-1)]+1;
    for(int i=0;i<1<<n;i++) {
        if(st[i]) dp[i]=max(dp[i],p[cnt[i]]);
        for(int j=i;j;j=(j-1)&i) if(st[i^j]) {
            dp[i]=max(dp[i],dp[j]+p[cnt[i]]);
        }
        for(int j=0;j<n;j++) if(i&(1<<j)) {
            dp[i]=max(dp[i],dp[i^(1<<j)]);
        }
    }
    cout<<sum-dp[(1<<n)-1]<<'\n';
    return 0;
}