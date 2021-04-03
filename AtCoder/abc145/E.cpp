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
const int N=3005;
PII a[N];
int n,m,dp[N<<1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].FI>>a[i].SE;
    sort(a+1,a+1+n);
    int mx=0;
    for(int i=1;i<=n;i++) {
        for(int j=m+a[i].FI-1;j>=a[i].FI;j--)
            dp[j]=max(dp[j],dp[j-a[i].FI]+a[i].SE);
        mx=max(mx,dp[m+a[i].FI-1]);
    }
    cout<<mx<<'\n';
    return 0;
}