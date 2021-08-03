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
int tot[N];
int build(int l,int r) {
    if(tot[r-l+1]) return tot[r-l+1];
    int t=1;
    if(l==r) return tot[r-l+1]=t;
    if(r-l==1) {
        int mid=l+r>>1;
        t+=build(l,l);
        t+=build(r,r);
    }
    else {
        int b=l+(r-l+2)/3-1;
        int c=b+r>>1;
        t+=build(l,b);
        t+=build(b+1,c);
        t+=build(c+1,r);
    }
    return tot[r-l+1]=t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
        }
        cout<<build(1,n)<<'\n';
    }
    return 0;
}