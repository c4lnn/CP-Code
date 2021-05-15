#include <bits/stdc++.h>
#define int long long
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int n,a[N];
struct Seg {
    int l,r,w;
}tr[N<<2];
void build(int p,int l,int r) {
    tr[p].l=l,tr[p].r=r;
    if(l==r) {
        tr[p].w=a[l];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tr[p].w=tr[p<<1].w+tr[p<<1|1].w;
}
void update(int p,int l,int r) {
    if(tr[p].w==tr[p].r-tr[p].l+1) return;
    if(tr[p].l==tr[p].r) {
        tr[p].w=(int)sqrt(tr[p].w);
        return;
    }
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid) update(p<<1,l,r);
    if(r>mid) update(p<<1|1,l,r);
    tr[p].w=tr[p<<1].w+tr[p<<1|1].w;
}
int query(int p,int l,int r) {
    if(tr[p].l>=l&&tr[p].r<=r) return tr[p].w;
    int mid=tr[p].l+tr[p].r>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
signed main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int cs=0;
    while(~scanf("%lld",&n)) {
        printf("Case #%lld:\n",++cs);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        build(1,1,n);
        int t;
        scanf("%lld",&t);
        for(int i=1;i<=t;i++) {
            int o,l,r;
            scanf("%lld%lld%lld",&o,&l,&r);
            if(l>r) swap(l,r);
            if(o==0) update(1,l,r);
            else printf("%lld\n",query(1,l,r));
        }
        puts("");
    }
    return 0;
}