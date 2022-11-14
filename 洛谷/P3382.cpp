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
DB l,r,a[20];
int n;
DB calc(DB x) {
    DB ret=0;
    for(int i=0;i<=n;i++) ret=ret*x+a[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<100;i++) {
        DB mid=(r-l)/3.0;
        if(calc(l+mid)>calc(r-mid)) r=r-mid;
        else l=l+mid;
    }
    cout<<fixed<<setprecision(5)<<l<<'\n';
    return 0;
}