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
const int N=25;
int a[N],k;
LL solve(LL x) {
    LL ret=x;
    for(int i=1;i<1<<k;i++) {
        int tot=0;
        __int128 d=1;
        for(int j=0;j<k;j++) if(i&(1<<j)) {
            ++tot;
            d*=a[j];
        }
        if(d>x) continue;
        ret+=(x/d)*(tot&1?-1:1);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL l,r;cin>>l>>r>>k;
    for(int i=0;i<k;i++) cin>>a[i];
    cout<<solve(r)-solve(l-1)<<'\n';
    return 0;
}