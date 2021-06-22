#include <bits/stdc++.h>
#define int long long
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int MOD=1e9+7;
const int N=1e5+5;
int n,a[N],b[N];
int fpow(int a,int b) {
    int res=1;
    while(b) {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
signed main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%lld",&n);
    int t=1,tt=1;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),t=t*a[i]%MOD;
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]),tt=tt*(a[i]-b[i])%MOD;
    if(tt==0) puts("1");
    else printf("%lld\n",((t+MOD-tt)%MOD)*fpow(t,MOD-2)%MOD);
    return 0;
}