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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    VI a(n+n),dp(n);
    for(int i=0;i<n;i++) cin>>a[i],a[i+n]=a[i];
    int res=n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) dp[j]=0x3f3f3f3f;
        for(int j=i;j<i+n;j++) *lower_bound(ALL(dp),a[j])=a[j];
        res=min(res,n-(int)(lower_bound(ALL(dp),0x3f3f3f3f)-dp.begin()));
    }
    cout<<res<<'\n';
    return 0;
}