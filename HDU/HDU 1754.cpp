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
const int N=2e5+5;
int n,m,a[N];
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
    tr[p].w=max(tr[p<<1].w,tr[p<<1|1].w);
}
void update(int p,int x,int w) {
    if(tr[p].l==tr[p].r&&tr[p].l==x) {
        tr[p].w=w;
        return;
    }
    int mid=tr[p].l+tr[p].r>>1;
    if(x<=mid) update(p<<1,x,w);
    else if(x>mid) update(p<<1|1,x,w);
    tr[p].w=max(tr[p<<1].w,tr[p<<1|1].w);
}
int query(int p,int l,int r) {
    if(tr[p].l>=l&&tr[p].r<=r) return tr[p].w;
    int mid=tr[p].l+tr[p].r>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return max(query(p<<1,l,r),query(p<<1|1,l,r));
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        for(int i=1;i<=m;i++) {
            char c;
            int a,b;
            scanf(" %c%d%d",&c,&a,&b);
            if(c=='U') update(1,a,b);
            else printf("%d\n",query(1,a,b));
        }
    }
    return 0;
}