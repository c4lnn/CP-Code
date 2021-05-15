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
int dp[105][105],f[105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    while(cin>>a>>b) {
        int n=SZ(a);
        memset(dp,0x3f,sizeof dp);
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++)
            for(int l=0;l+len-1<n;l++) {
                int r=l+len-1;
                if(b[l]==b[r]) dp[l][r]=dp[l+1][r];
                else for(int k=l;k<r;k++) dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
        f[0]=a[0]!=b[0];
        for(int i=1;i<n;i++) {
            if(a[i]==b[i]) f[i]=f[i-1];
            else {
                f[i]=dp[0][i];
                for(int j=0;j<i;j++) f[i]=min(f[i],f[j]+dp[j+1][i]);
            }
        }
        cout<<f[n-1]<<'\n';
    }
    return 0;
}