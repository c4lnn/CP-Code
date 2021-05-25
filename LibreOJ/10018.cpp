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
//head
const int N=1e3+5;
int n,m,dp[N][N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        int x=min(i,m);
        for(int j=1;j<=x;j++) {
            dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
        }
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}