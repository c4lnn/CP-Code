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
const int N=3e3+5;
int n,m;
LL s[N],dp[N][N],q[N],x[N],y[N];
LD slope(int a,int b) {
    return 1.0*(y[b]-y[a])/(x[b]-x[a]);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;i++) dp[i][1]=s[i]*s[i];
    for(int j=2;j<=m;j++) {
        int l=1,r=0;
        q[++r]=0;
        for(int i=1;i<=n;i++) {
            while(l<r&&slope(q[l],q[l+1])<=2*s[i]) ++l;
            dp[i][j]=dp[q[l]][j-1]+(s[i]-s[q[l]])*(s[i]-s[q[l]]);
            x[i]=s[i],y[i]=dp[i][j-1]+s[i]*s[i];
            while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i)) --r;
            q[++r]=i;
        }
    }
    cout<<-s[n]*s[n]+m*dp[n][m]<<'\n';
    return 0;
}