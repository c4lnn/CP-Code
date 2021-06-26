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
const int N=2e5+5;
int n,x,a[N];
signed main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%lld%lld",&n,&x);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int tot=0,res=0;
    for(int i=1;i<=n;i++) {
        if(a[i]-tot==0) continue;
        if(x<n-i+1) res+=(a[i]-tot)*x,tot+=a[i]-tot;
        else res+=a[i]-tot;
    }
    printf("%lld\n",res);
    return 0;
}