#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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
LL MOD=1000000007;
LL dp[55][55][15][15],w[55][55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,o;cin>>n>>m>>o;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>w[i][j];
            ++w[i][j];
        }
    }
    dp[1][1][0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i==1&&j==1) continue;
            dp[i][j][0][0]=(dp[i-1][j][0][0]+dp[i][j-1][0][0])%MOD;
        }
    }
    dp[1][1][1][w[1][1]]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i==1&&j==1) continue;
            for(int k=1;k<=o;k++) {
                for(int l=1;l<=13;l++) {
                    dp[i][j][k][l]=(dp[i-1][j][k][l]+dp[i][j-1][k][l])%MOD;
                }
                for(int l=0;l<w[i][j];l++) {
                    dp[i][j][k][w[i][j]]=(dp[i][j][k][w[i][j]]+dp[i-1][j][k-1][l]+dp[i][j-1][k-1][l])%MOD;
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<=13;i++) res=(res+dp[n][m][o][i])%MOD;
    cout<<res<<'\n';
    return 0;
}