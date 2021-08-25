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
const int N=1e5+5;
LL a[N],b[N],sum1[N],sum2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,s,t;LL h;cin>>n>>s>>t>>h;
        for(int i=1;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++) cin>>b[i];
        sort(a+1,a+n);
        sort(b+1,b+n);
        for(int i=1;i<n;i++) sum1[i]=sum1[i-1]+a[i];
        for(int i=1;i<n;i++) sum2[i]=sum2[i-1]+b[i];
        LL res=LLONG_MAX;
        if(t&&sum1[n-1-s]-sum1[t-1]>sum2[n-1-s]-sum2[t-1]) res=min(res,1-b[t]);
        if(t&&sum1[n-1-s]-sum1[t-1]>sum2[n-1-s]-sum2[t]+b[t]) res=min(res,1-min(s?b[n-s]:h,sum1[n-1-s]-sum1[t-1]-sum2[n-1-s]+sum2[t]-1));
        if(s&&t&&sum1[n-1-s]-sum1[t-1]>sum2[n-s]-sum2[t]) res=min(res,1-h);
        if(t&&sum1[n-1-s]-sum1[t]+(s?a[n-s]:h)>sum2[n-1-s]-sum2[t-1]) res=min(res,max(sum2[n-1-s]-sum2[t-1]-sum1[n-1-s]+sum1[t]+1,a[t])-b[t]);
        if(sum1[n-1-s]-sum1[t]+(s?a[n-s]:h)>sum2[n-1-s]-sum2[t]+(t?b[t]:1)) res=min(res,max((t?a[t]:1)-(s?b[n-s]:h),sum2[n-1-s]-sum2[t]-sum1[n-1-s]+sum1[t]+1));
        if(s&&sum1[n-1-s]-sum1[t]+a[n-s]>sum2[n-s]-sum2[t]) res=min(res,max(sum2[n-s]-sum2[t]-sum1[n-1-s]+sum1[t]+1,t?a[t]:1)-h);
        if(s&&t&&sum1[n-s]-sum1[t]>sum2[n-1-s]-sum2[t-1]) res=min(res,a[n-s]-b[t]);
        if(s&&sum1[n-s]-sum1[t]>sum2[n-1-s]-sum2[t]+(t?b[t]:1)) res=min(res,a[n-s]-min(b[n-s],sum1[n-s]-sum1[t]-sum2[n-1-s]+sum2[t]-1));
        if(s&&sum1[n-s]-sum1[t]>sum2[n-s]-sum2[t]) res=min(res,a[n-s]-h);
        if(res==LLONG_MAX) cout<<"IMPOSSIBLE"<<'\n';
        else cout<<res<<'\n';
    }
    return 0;
}