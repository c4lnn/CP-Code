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
const int N=1005;
int h[N],s[N],w[N];
LL dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,H,S;cin>>n>>H>>S;
    for(int i=1;i<=n;i++) {
        cin>>h[i]>>s[i]>>w[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j=h[i]+1;j<=H;j++) {
            for(int k=0;k<=S;k++) {
                if(k-s[i]>=0) dp[j-h[i]][k-s[i]]=max(dp[j-h[i]][k-s[i]],dp[j][k]+w[i]);
                else {
                    int d=s[i]-k;
                    if(j-h[i]-d>0) dp[j-h[i]-d][0]=max(dp[j-h[i]-d][0],dp[j][k]+w[i]);
                }
            }
        }
    }
    LL res=0;
    for(int i=1;i<=H;i++) {
        for(int j=0;j<=S;j++) {
            res=max(res,dp[i][j]);
        }
    }
    cout<<res<<'\n';
    return 0;
}