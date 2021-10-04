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
const int N=1e6+5;
int a[N],dp[N][2];
bool vis[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        ++a[x];
    }
    for(int i=1;i<=1e6;i++) if(!vis[i]) {
        dp[i][0]=0;
        dp[i][1]=a[i];
        vis[i]=true;
        for(int j=i*2;j<=1e6;j*=2) {
            if(a[j/2]) dp[j][0]=dp[j/2][1];
            else dp[j][0]=min(dp[j/2][0],dp[j/2][1]);
            dp[j][1]=min(dp[j/2][0],dp[j/2][1])+a[j];
            vis[j]=true;
        }
    }
    int sum=0;
    for(int i=500001;i<=1e6;i++) sum+=min(dp[i][0],dp[i][1]);
    cout<<sum<<'\n';
    return 0;
}