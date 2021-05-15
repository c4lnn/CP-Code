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
const int N=105;
int a[N],dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++) {
            for(int l=1;l+len-1<=n;l++) {
                int r=l+len-1;
                dp[l][r]=INT_MAX;
                if(a[l]==a[r]) dp[l][r]=dp[l][r-1];
                else for(int i=l;i<r;i++) dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
            }
        }
        cout<<"Case "<<cs<<": "<<dp[1][n]<<'\n';
    }
    return 0;
}