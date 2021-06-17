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
const int N=3e5+5;
int a[N],pos[N];
int ls[N<<2],rs[N<<2],add[N<<2],mn[N<<2],cnt1[N<<2],cnt2[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    cnt1[p]=r-l+1;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void push_down(int p) {
    if(add[p]) {
        mn[p<<1]+=add[p],mn[p<<1|1]+=add[p];
        add[p<<1]+=add[p],add[p<<1|1]+=add[p];
        add[p]=0;
    }
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        mn[p]+=v;
        add[p]+=v;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    cnt1[p]=cnt1[p<<1]*(mn[p<<1]==mn[p])+cnt1[p<<1|1]*(mn[p<<1|1]==mn[p]);
    cnt2[p]=cnt1[p<<1]*(mn[p<<1]==mn[p]+1)+cnt1[p<<1|1]*(mn[p<<1|1]==mn[p]+1);
    cnt2[p]+=cnt2[p<<1]*(mn[p<<1]==mn[p])+cnt2[p<<1|1]*(mn[p<<1|1]==mn[p]);
}
int query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return cnt1[p]*(mn[p]<=2)+cnt2[p]*(mn[p]==1);
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        pos[x]=i;
    }
    build(1,1,n);
    LL res=0;
    for(int i=1;i<=n;i++) {
        a[pos[i]]=i;
        int x=a[pos[i]-1],y=a[pos[i]+1];
        if(x>y) swap(x,y);
        if(x&&y) update(1,1,x,-1),update(1,y+1,i,1);
        else update(1,y+1,i,1);
        if(i>1) res+=query(1,1,i-1);
    }
    cout<<res<<'\n';
    return 0;
}