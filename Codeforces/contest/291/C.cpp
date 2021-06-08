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
int main() {
    int n,k;scanf("%d%d",&n,&k);
    LL a,b,c,d;
    vector<LL> x(n+1);
    for(int i=1;i<=n;i++) {
        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
        x[i]=(a<<24)+(b<<16)+(c<<8)+d;
    }
    LL t=0;
    for(int i=31;i>=1;i--) {
        t+=1ll<<i;
        set<LL> s;
        for(int j=1;j<=n;j++) {
            s.insert(t&x[j]);
        }
        if(SZ(s)==k) {
            d=t-((t>>8)<<8);
            t>>=8;
            c=t-((t>>8)<<8);
            t>>=8;
            b=t-((t>>8)<<8);
            t>>=8;
            a=t;
            printf("%lld.%lld.%lld.%lld",a,b,c,d);
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}