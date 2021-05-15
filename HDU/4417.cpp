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
int n,m,a[N],cnt,ls[N*40],rs[N*40],w[N*40],rt[N];
VI b;
int build(int l,int r) {
    int p=++cnt;
    if(l==r) {ls[p]=rs[p]=w[p]=0;return p;}
    int mid=l+r>>1;
    ls[p]=build(l,mid);
    rs[p]=build(mid+1,r);
    w[p]=0;
    return p;
}
int insert(int now,int l,int r,int x) {
    int p=++cnt;
    ls[p]=ls[now],rs[p]=rs[now],w[p]=w[now];
    if(l==r) {++w[p];return p;}
    int mid=l+r>>1;
    if(x<=mid) ls[p]=insert(ls[now],l,mid,x);
    else rs[p]=insert(rs[now],mid+1,r,x);
    w[p]=w[ls[p]]+w[rs[p]];
    return p;
}
int query(int p,int q,int lc,int rc,int l,int r) {
    if(l<=lc&&r>=rc) return w[q]-w[p];
    int mid=lc+rc>>1;
    if(r<=mid) return query(ls[p],ls[q],lc,mid,l,r);
    if(l>mid) return query(rs[p],rs[q],mid+1,rc,l,r);
    return query(ls[p],ls[q],lc,mid,l,r)+query(rs[p],rs[q],mid+1,rc,l,r);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        printf("Case %d:\n",cs);
        cnt=0;
        b.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b.PB(a[i]);
        sort(ALL(b));
        b.resize(unique(ALL(b))-b.begin());
        rt[0]=build(1,SZ(b));
        for(int i=1;i<=n;i++) rt[i]=insert(rt[i-1],1,SZ(b),lower_bound(ALL(b),a[i])-b.begin()+1);
        for(int i=1;i<=m;i++) {
            int l,r,h;
            scanf("%d%d%d",&l,&r,&h);
            ++l,++r;
            int t=lower_bound(ALL(b),h)-b.begin();
            if(b[t]==h) ++t;
            if(!t) puts("0");
            else printf("%d\n",query(rt[l-1],rt[r],1,SZ(b),1,t));
        }
    }
    return 0;
}