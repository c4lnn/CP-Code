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
const int N=2e5+5;
DB a[N],b[N],sum[N];
bool check(DB *a,int n,int m,DB mid) {
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i]-mid;
    }
    DB mn=1e18;
    for(int i=1;i<=n;i++) {
        if(i>=m) mn=min(mn,sum[i-m]);
        if(sum[i]-mn>-1e-8) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x,y;cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    DB l=0,r=1e5;
    for(int i=0;i<100;i++) {
        DB mid=(l+r)/2.0;
        if(check(a,n,x,mid)) l=mid;
        else r=mid;
    }
    DB res=l;
    l=0,r=1e5;
    for(int i=0;i<100;i++) {
        DB mid=(l+r)/2.0;
        if(check(b,m,y,mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(10)<<res+l<<'\n';
    return 0;
}