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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=105;
LL x[N],y[N];
LL gcd(LL a,LL b) {
    return b?gcd(b,a%b):a;
}
int main() {
    int n;scanf("%d",&n);
    LL lcm=1;
    int i;
    for(i=1;i<=n;i++) {
        scanf("%lld/%lld",&x[i],&y[i]);
        LL d=gcd(lcm,y[i]);
        lcm=lcm*y[i]/d;
    }
    LL sum=0;
    for(i=1;i<=n;i++) {
        sum+=lcm/y[i]*x[i];
    }
    LL d=gcd(sum,lcm);
    sum/=d,lcm/=d;
    if(lcm==1) printf("%lld\n",sum);
    else if(abs(sum)>lcm) {
        printf("%lld ",sum/lcm);
        sum%=lcm;
        printf("%lld/%lld",sum,lcm);
    }
    else printf("%lld/%lld",sum,lcm);
    return 0;
}