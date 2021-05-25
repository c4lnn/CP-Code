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
const int N=1e4+5;
int n;
LL s,t[N],c[N],dp[N],q[N],x[N],y[N];
LD slope(int a,int b) {
    return (LD)(y[b]-y[a])/(x[b]-x[a]);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=1;i<=n;i++) {
        cin>>t[i]>>c[i];
        t[i]+=t[i-1];
        c[i]+=c[i-1];
    }
    int l=1,r=0;
    q[++r]=0;
    for(int i=1;i<=n;i++) {
        while(l<r&&slope(q[l],q[l+1])<=t[i]) ++l;
        dp[i]=dp[q[l]]+t[i]*(c[i]-c[q[l]])+s*(c[n]-c[q[l]]);
        x[i]=c[i],y[i]=dp[i]-s*c[i];
        while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i)) --r;
        q[++r]=i;
    }
    cout<<dp[n]<<'\n';
    return 0;
}