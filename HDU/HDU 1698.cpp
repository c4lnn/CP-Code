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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int n,m;
struct seg {
    int l,r,w,add;
}tr[N<<2];
void build(int p,int l,int r) {
    tr[p].l=l,tr[p].r=r;
    if(l==r){tr[p].w=1,tr[p].add=0;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tr[p].w=tr[p<<1].w+tr[p<<1|1].w;
    tr[p].add=0;
}
void pushdown(int p) {
    if(tr[p].add) {
        tr[p<<1].w=(tr[p<<1].r-tr[p<<1].l+1)*tr[p].add;
        tr[p<<1|1].w=(tr[p<<1|1].r-tr[p<<1|1].l+1)*tr[p].add;
        tr[p<<1].add=tr[p].add,tr[p<<1|1].add=tr[p].add;
        tr[p].add=0;
    }
}
void update(int p,int l,int r,int v) {
    if(tr[p].l>=l&&tr[p].r<=r) {
        tr[p].w=(tr[p].r-tr[p].l+1)*v;
        tr[p].add=v;
        return;
    }
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    tr[p].w=tr[p<<1].w+tr[p<<1|1].w;
}
int query(int p,int l,int r) {
    if(tr[p].l>=l&&tr[p].r<=r) return tr[p].w;
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%d%d",&n,&m);
        build(1,1,n);
        for(int i=1;i<=m;i++) {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            update(1,l,r,x);
        }
        printf("Case %d: The total value of the hook is %d.\n",cs,query(1,1,n));
    }
    return 0;
}