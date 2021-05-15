#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define int long long
using namespace std;
typedef double DB;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int sum1[N],sum2[N],a[N],b[N],cnt1,cnt2,n,m,d;
signed main() {
    scanf("%lld%lld%lld",&n,&d,&m);
    for(int i=1;i<=n;i++) {
        int x;
        scanf("%lld",&x);
        if(x<=m) a[++cnt1]=x;
        else b[++cnt2]=x;
    }
    sort(a+1,a+1+cnt1,greater<int>());
    sort(b+1,b+1+cnt2,greater<int>());
    for(int i=1;i<=cnt1;i++) sum1[i]=sum1[i-1]+a[i];
    for(int i=1;i<=cnt2;i++) sum2[i]=sum2[i-1]+b[i];
    int res=sum1[cnt1];
    for(int i=1;i<=cnt2;i++) {
        int t=n-(d+1)*i+d;
        if(t<0) break;
        res=max(res,sum1[min(t,cnt1)]+sum2[i]);
    }
    printf("%lld\n",res);
    return 0;
}