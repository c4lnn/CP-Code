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
int d[N],sum[N],dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>d[i];
            sum[i]=sum[i-1]+d[i];
        }
        for(int len=2;len<=n;len++) {
            for(int l=1;l+len-1<=n;l++) {
                int r=l+len-1;
                dp[l][r]=min(dp[l+1][r]+d[l]*(len-1),dp[l][r-1]+d[r]*(len-1));
                for(int i=l+1;i<r;i++) dp[l][r]=min(dp[l][r],dp[l][i-1]+d[i]*(len-1)+dp[i+1][r]+(sum[r]-sum[i])*(i-l));
            }
        }
        cout<<"Case #"<<cs<<": "<<dp[1][n]<<'\n';
    }
    return 0;
}