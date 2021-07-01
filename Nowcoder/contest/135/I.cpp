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
const int N=1e6+5;
LL a[N],b[N];
int main() {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        int q,l,r,p;cin>>q>>l>>r>>p;
        if(q==1) b[l]-=p,b[r+1]+=p;
        else b[l]+=p,b[r+1]-=p;
    }
    int l,r;cin>>l>>r;
    LL res=0;
    for(int i=1;i<=r;i++) {
        b[i]+=b[i-1];
        if(i>=l) res+=a[i]+b[i];
    }
    cout<<res;
    return 0;
}