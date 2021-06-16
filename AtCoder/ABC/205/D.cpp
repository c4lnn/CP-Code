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
vector<LL> a;
LL dfs(int l,int r,LL k) {
    if(r-l==1) return a[l]+k;
    int mid=l+r>>1;
    if(a[mid]-a[l]-mid+l>=k) return dfs(l,mid,k);
    return dfs(mid,r,k-(a[mid]-a[l]-mid+l));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++) {
        LL x;cin>>x;
        a.PB(x);
    }
    a.PB(0);
    a.PB(1e18+n);
    sort(ALL(a));
    a.resize(unique(ALL(a))-a.begin());
    while(q--) {
        LL k;cin>>k;
        cout<<dfs(0,SZ(a)-1,k)<<'\n';
    }
    return 0;
}