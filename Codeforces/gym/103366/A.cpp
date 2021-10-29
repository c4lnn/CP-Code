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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const LL MOD=998244353;
const int N=505;
int a[N][N];
LL dp[2][N][N*2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,p,q;cin>>n>>m>>p>>q;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    dp[1][1][!a[1][1]]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i==1&&j==1) continue;
            for(int k=0;i+j-1>=k;k++) {
                dp[i&1][j][k]=0;
                if(a[i][j]==0) {
                    if(!k) continue;
                    dp[i&1][j][k]=(dp[i&1][j-1][k-1]+dp[(i-1)&1][j][k-1])%MOD;
                }
                else if(i+j-1-k) dp[i&1][j][k]=(dp[i&1][j-1][k]+dp[(i-1)&1][j][k])%MOD;
            }

        }
    }
    LL res=0;
    for(int i=p;n+m-1-i>=q;i++) {
        res=(res+dp[n&1][m][i])%MOD;
    }
    cout<<res<<'\n';
    return 0;
}