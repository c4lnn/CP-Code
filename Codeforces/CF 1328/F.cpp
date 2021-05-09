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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=2e5+5;
int n,k;
LL a[N],tot[N],sum[N],c[N],d[N];
vector<LL> b;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        b.PB(a[i]);
    }
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=n;i++) ++tot[lower_bound(ALL(b),a[i])-b.begin()];
    sum[0]=tot[0];
    for(int i=1;i<SZ(b);i++) sum[i]=tot[i]+sum[i-1];
    for(int i=1;i<SZ(b);i++) c[i]=c[i-1]+sum[i-1]*(b[i]-b[i-1]);
    for(int i=SZ(b)-2;i>=0;i--) d[i]=d[i+1]+(sum[SZ(b)-1]-sum[i])*(b[i+1]-b[i]);
    LL mn=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<SZ(b);i++) {
        if(tot[i]>=k) {puts("0");return 0;}
        LL sum1=0,sum2=0;
        if(i-1>=0) sum1=c[i-1]+sum[i-1]*(b[i]-b[i-1]-1);
        if(i+1<SZ(b)) sum2=d[i+1]+(sum[SZ(b)-1]-sum[i])*(b[i+1]-b[i]-1);
        if(i-1>=0&&sum[i-1]+tot[i]>=k) mn=min(mn,sum1+k-tot[i]);
        if(sum[SZ(b)-1]-sum[i]+tot[i]>=k) mn=min(mn,sum2+k-tot[i]);
        mn=min(mn,sum1+sum2+k-tot[i]);
    }
    printf("%lld\n",mn);
    return 0;
}