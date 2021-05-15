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
const int N=1e6+5;
int n;
LL a,b,c,s[N],dp[N],q[N],x[N],y[N];
LD slope(int a,int b) {
    return 1.0*(y[b]-y[a])/(x[b]-x[a]);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>a>>b>>c;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    int l=1,r=0;
    q[++r]=0;
    for(int i=1;i<=n;i++) {
        while(l<r&&slope(q[l],q[l+1])>=2*a*s[i]) ++l;
        dp[i]=dp[q[l]]+a*(s[i]-s[q[l]])*(s[i]-s[q[l]])+b*(s[i]-s[q[l]])+c;
        x[i]=s[i],y[i]=dp[i]+a*s[i]*s[i]-b*s[i];
        while(l<r&&slope(q[r-1],q[r])<=slope(q[r],i)) --r;
        q[++r]=i;
    }
    cout<<dp[n]<<'\n';
    return 0;
}