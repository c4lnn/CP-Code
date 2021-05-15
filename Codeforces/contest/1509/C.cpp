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
const int N=2005;
LL a[N],dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int len=2;len<=n;len++) {
        for(int l=1;l+len-1<=n;l++) {
            int r=l+len-1;
            dp[l][r]=a[r]-a[l]+min(dp[l+1][r],dp[l][r-1]);
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}