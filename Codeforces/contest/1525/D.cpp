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
const int N=5005;
int a[N],b[N],cnt1,cnt2,dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        if(x==1) a[++cnt1]=i;
        else b[++cnt2]=i;
    }
    if(cnt1==0) return cout<<0<<'\n',0;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=cnt2;i++) dp[1][i]=min(dp[1][i-1],abs(a[1]-b[i]));
    for(int i=2;i<=cnt1;i++)
        for(int j=1;j<=cnt2;j++)
            dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[i]-b[j]));
    cout<<dp[cnt1][cnt2]<<'\n';
    return 0;
}