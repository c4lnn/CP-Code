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
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=105;
int n,a[N],b[N],dp[N][N*N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        sum+=b[i];
    }
    memset(dp,0xc0,sizeof dp);
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=n;j>=1;j--) {
            for(int k=a[i];k<=10000;k++) {
                dp[j][k]=max(dp[j][k],dp[j-1][k-a[i]]+b[i]);
            }
        }
    }
    cout<<fixed<<setprecision(10);
    for(int i=1;i<=n;i++) {
        int mx=0;
        for(int j=1;j<=10000;j++) {
            mx=max(mx,min(2*j,dp[i][j]+sum));
        }
        cout<<mx/2.0<<' ';
    }
    cout<<'\n';
    return 0;
}