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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<LL> dp(n+1),sum(n+2);
    for(int i=n;i>=1;i--) {
        if(i==n) dp[i]=1;
        else {
            dp[i]=(dp[i]+sum[i+1])%m;
            for(int j=2;i*j<=n;j++) {
                dp[i]=(dp[i]+(sum[i*j]-(i*j+j>n?0:sum[i*j+j])+m)%m)%m;
            }
        }
        sum[i]=(sum[i+1]+dp[i])%m;
    }
    cout<<dp[1]<<'\n';
    return 0;
}