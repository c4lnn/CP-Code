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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        LL n;
        scanf("%lld",&n);
        LL res=0;
        for(LL l=1,r;l<=n;l=r+1) {
            r=min(n,n/(n/l));
            res+=(r-l+1)*(n/l);
        }
        printf("Case %d: %lld\n",cs,res);
    }
    return 0;
}