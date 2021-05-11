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
LL n,k;
LL calc(LL sum) {
    LL ret=(sum-1)*(sum-2)/2;
    if(sum-n-2>0) ret-=3*(sum-n-1)*(sum-n-2)/2;
    if(sum-2*n-2>0) ret+=3*(sum-2*n-1)*(sum-2*n-2)/2;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(LL i=3;i<=3*n;i++) {
        LL ret=calc(i);
        if(ret<k) k-=ret;
        else {
            for(LL j=max(1ll,i-2*n);j<=n;j++) {
                LL t=min(n,i-j-1)-max(1ll,i-j-n)+1;
                if(t<k) k-=t;
                else return cout<<j<<' '<<max(1ll,i-j-n)+k-1<<' '<<i-j-(max(1ll,i-j-n)+k-1)<<'\n',0;
            }
        }
    }
    return 0;
}