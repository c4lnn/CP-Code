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
const int N=1e5+5;
pair<PII,PII> a[N];
int n,b[N],ls[N<<2],rs[N<<2],mn[N<<2],mx[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        mn[p]=a[l].SE.SE;
        mx[p]=a[l].SE.FI;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
PII query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return MP(mn[p],mx[p]);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    PII ll=query(p<<1,l,r),rr=query(p<<1|1,l,r);
    return MP(min(ll.FI,rr.FI),max(ll.SE,rr.SE));
}
bool cmp (pair<PII,PII> a,pair<PII,PII> b) {
    return a.FI.FI<b.FI.FI;
}
bool solve() {
    sort(a+1,a+1+n,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++) b[++cnt]=a[i].FI.FI;
    build(1,1,n);
    for(int i=1;i<=n;i++) {
        int pos=upper_bound(b+1,b+1+n,a[i].FI.SE)-b-1;
        if(i+1>pos) continue;
        PII t=query(1,i+1,pos);
        if(t.FI<a[i].SE.FI||t.SE>a[i].SE.SE) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].FI.FI>>a[i].FI.SE>>a[i].SE.FI>>a[i].SE.SE;
    if(!solve()) return cout<<"NO"<<'\n',0;
    for(int i=1;i<=n;i++) swap(a[i].FI,a[i].SE);
    cout<<(solve()?"YES":"NO")<<'\n';
    return 0;
}