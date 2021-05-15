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
int n,m,k;
signed main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%lld",&tt);
    while(tt--) {
        scanf("%lld%lld%lld",&n,&m,&k);
        int res=0,mn=0x3f3f3f3f;
        for(int i=1;i<=m;i++) {
            int x;
            scanf("%lld",&x);
            mn=min(mn,x);
            res+=abs(x-k)<<1;
        }
        res+=(k-1)<<1;
        if(mn<k) res-=k-mn<<1;
        printf("%lld\n",res);
    }
    return 0;
}