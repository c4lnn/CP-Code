#include <cstdio>
#include <algorithm>
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+5;
int a[N];
struct R {
    int ls,rs,mx;
    PII ll,rr;
}node[N<<2];
void push_up(R &a,R b,R c) {
    a.ls=b.ls,a.rs=c.rs;
    a.mx=max(b.mx,c.mx);
    if(b.rr.FI==c.ll.FI) a.mx=max(a.mx,b.rr.SE+c.ll.SE);
    a.ll.FI=b.ll.FI;
    a.ll.SE=b.ll.SE+(b.ll.SE==b.rs-b.ls+1&&b.ll.FI==c.ll.FI?c.ll.SE:0);
    a.rr.FI=c.rr.FI;
    a.rr.SE=c.rr.SE+(c.rr.SE==c.rs-c.ls+1&&c.rr.FI==b.rr.FI?b.rr.SE:0);
}
void build(int p,int l,int r) {
    if(l==r) {
        node[p].ls=node[p].rs=l;
        node[p].mx=1;
        node[p].ll=node[p].rr=MP(a[l],1);
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(node[p],node[p<<1],node[p<<1|1]);
}
R query(int p,int l,int r) {
    if(node[p].ls>=l&&node[p].rs<=r) return node[p];
    int mid=node[p].ls+node[p].rs>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    R ret=query(p<<1,l,r);
    push_up(ret,ret,query(p<<1|1,l,r));
    return ret;
}
int main() {
    int n,q;
    while(~scanf("%d",&n)&&n) {
        scanf("%d",&q);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        for(int i=1;i<=q;i++) {
            int l,r;scanf("%d%d",&l,&r);
            printf("%d\n",query(1,l,r).mx);
        }
    }
    return 0;
}