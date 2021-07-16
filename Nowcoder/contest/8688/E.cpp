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
LL a[N],dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n) {
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dp[i][j]=0x3f3f3f3f;
            }
        }
        for(int i=1;i<n;i++) dp[i][i+1]=0;
        for(int len=3;len<=n;len++) {
            for(int x=2;x<n;x++) {
                for(int l=min(x-1,n-len+1);l>=1&&x-l+2<=len;l--) {
                    int r=l+len-1;
                    dp[l][r]=min(dp[l][r],dp[l][x]+dp[x][r]+(a[l]+a[x]+a[r])*(a[l]+a[x]+a[r]));
                }
            }
        }
        cout<<dp[1][n]<<'\n';
    }
    return 0;
}