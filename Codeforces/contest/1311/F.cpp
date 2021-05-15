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
int n;
PII a[N];
LL c1[N],c2[N];
void update(int x,int v,LL *c) {
    for(int i=x;i<=n;i+=i&-i) c[i]+=v;
}
LL query(int x,LL *c) {
    LL ret=0;
    for(int i=x;i>=1;i-=i&-i) ret+=c[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].FI;
    VI b;
    for(int i=1;i<=n;i++) {
        cin>>a[i].SE;
        b.PB(a[i].SE);
    }
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    sort(a+1,a+1+n);
    LL res=0;
    for(int i=1;i<=n;i++) {
        int pos=lower_bound(ALL(b),a[i].SE)-b.begin()+1;
        res+=query(pos,c2)*a[i].FI-query(pos,c1);
        update(pos,a[i].FI,c1);
        update(pos,1,c2);
    }
    cout<<res<<'\n';
    return 0;
}