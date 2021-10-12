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
const int N=2e5+5;
int a[N],b[N];
struct R {
    int ls,rs,llen,rlen;
    LL sum;
    R() {}
    R(int ls,int rs,int llen,int rlen,LL sum):ls(ls),rs(rs),llen(llen),rlen(rlen),sum(sum) {}
} node[N<<2];
R merge(R &x,R &y) {
    R ret;
    ret.ls=x.ls,ret.rs=y.rs;
    ret.sum=x.sum+1ll*x.rlen*y.llen+y.sum;
    ret.llen=x.llen+(x.llen==(x.rs-x.ls+1)?y.llen:0);
    ret.rlen=y.rlen+(y.rlen==(y.rs-y.ls+1)&&b[y.ls]>=0?x.rlen:0);
    return ret;
}
void build(int p,int l,int r) {
    node[p].ls=l,node[p].rs=r;
    if(l==r) {
        node[p].sum=1;
        if(b[l]>=0) node[p].llen=node[p].rlen=1;
        else node[p].llen=0,node[p].rlen=1;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    node[p]=merge(node[p<<1],node[p<<1|1]);
}
void update(int p,int x,int v) {
    if(node[p].ls==node[p].rs) {
        node[p].sum=1;
        if(v>=0) node[p].llen=node[p].rlen=1;
        else node[p].llen=0,node[p].rlen=1;
        return;
    }
    int mid=node[p].ls+node[p].rs>>1;
    if(x<=mid) update(p<<1,x,v);
    else update(p<<1|1,x,v);
    node[p]=merge(node[p<<1],node[p<<1|1]);
}
R query(int p,int l,int r) {
    if(node[p].ls>=l&&node[p].rs<=r) return node[p];
    int mid=node[p].ls+node[p].rs>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    R ln=query(p<<1,l,r),rn=query(p<<1|1,l,r);
    return merge(ln,rn);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    build(1,1,n);
    while(q--) {
        int o;cin>>o;
        if(o==1) {
            int x,v;cin>>x>>v;
            a[x]=v;
            if(x!=1) b[x]=a[x]-a[x-1],update(1,x,b[x]);
            if(x!=n) b[x+1]=a[x+1]-a[x],update(1,x+1,b[x+1]);
        }
        else {
            int l,r;cin>>l>>r;
            cout<<query(1,l,r).sum<<'\n';
        }
    }
    return 0;
}