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
int n,m;
vector<LL> a,b;
bool check(LL mid) {
    for(int i=0,j=0;i<n;i++) {
        if(abs(b[j]-a[i])>mid) continue;
        if(b[j]>a[i]) {
            while(b[j]<=a[i]+mid) if(++j==m) return true;
        }
        else {
            LL t=max({b[j]+mid-abs(a[i]-b[j]),a[i]+(mid-(a[i]-b[j]))/2,a[i]});
            while(b[j]<=t) if(++j==m) return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    a.resize(n);
    b.resize(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    LL l=0,r=2e10;
    while(l<r) {
        LL mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
    return 0;
}