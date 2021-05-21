#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int n,a[N][N],dp[N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>a[i][j];
        }
    }
    dp[1][1][0]=a[1][1];
    for(int i=1;i<n;i++) {
        for(int j=1;j<=i;j++) {
            for(int k=0;k<i;k++) {
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i+1][j]);
                dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k+1],dp[i][j][k]+a[i+1][j+1]);
            }
        }
    }
    if(n&1) cout<<dp[n][n+1>>1][n>>1]<<'\n';
    else cout<<max(dp[n][n>>1][n-1>>1],dp[n][n+2>>1][n>>1])<<'\n';
    return 0;
}