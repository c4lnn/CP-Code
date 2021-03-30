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
LL x[N],p[N],c[N],dp[N],s[N],ss[N],q[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>p[i]>>c[i];
        s[i]=s[i-1]+p[i];
        ss[i]=ss[i-1]+p[i]*x[i];
    }
    int l=1,r=0;
    q[++r]=0;
    for(int i=1;i<=n;i++) {
        while(r>l&&(ss[q[l+1]]+dp[q[l+1]]-ss[q[l]]-dp[q[l]]<=x[i]*(s[q[l+1]]-s[q[l]]))) ++l;
        dp[i]=dp[q[l]]+x[i]*(s[i]-s[q[l]])-(ss[i]-ss[q[l]])+c[i];
        while(r>l&&(ss[q[r]]+dp[q[r]]-ss[q[r-1]]-dp[q[r-1]])*(s[i]-s[q[r]])>=(ss[i]+dp[i]-ss[q[r]]-dp[q[r]])*(s[q[r]]-s[q[r-1]])) --r;
        q[++r]=i;
    }
    cout<<dp[n]<<'\n';
    return 0;
}