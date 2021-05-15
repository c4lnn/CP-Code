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
const int N=5e4+5;
int n;
LL L,s[N],dp[N],q[N];
LL X(LL x) {
    return s[x];
}
LL Y(LL x) {
    return dp[x]+s[x]*s[x]+2*L*s[x];
}
LD slope(LL a,LL b) {
    if(X(a)==X(b)) return Y(b)>=Y(a)?LDBL_MAX:LDBL_MIN;
    return (LD)(Y(b)-Y(a))/(X(b)-X(a));
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>L;
    ++L;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i]+=s[i-1]+1;
    }
    int l=1,r=0;
    q[++r]=0;
    for(int i=1;i<=n;i++) {
        while(l<r&&slope(q[l],q[l+1])<=2*s[i]) ++l;
        dp[i]=dp[q[l]]+(s[i]-s[q[l]]-L)*(s[i]-s[q[l]]-L);
        while(l<r&&slope(q[r-1],q[r])>=slope(q[r],i)) --r;
        q[++r]=i;
    }
    cout<<dp[n]<<'\n';
    return 0;
}