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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    VI a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int l,r;cin>>l>>r;
    sort(ALL(b));
    LL res=0;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            if(l<=0&&r>=0) res+=m;
        }
        else if(a[i]>0) {
            int lpos=lower_bound(ALL(b),l<0?l/a[i]:int(ceil(1.0*l/a[i])))-b.begin();
            int rpos=upper_bound(ALL(b),r<0?int(floor(1.0*r/a[i])):r/a[i])-b.begin()-1;
            res+=rpos-lpos+1;
        }
        else {
            int lpos=lower_bound(ALL(b),r<0?int(ceil(1.0*r/a[i])):r/a[i])-b.begin();
            int rpos=upper_bound(ALL(b),l<0?l/a[i]:int(floor(1.0*l/a[i])))-b.begin()-1;
            res+=rpos-lpos+1;
        }
    }
    cout<<res<<'\n';
    return 0;
}