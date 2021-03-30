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
const int N=8005;
int n,cnt[N],a[N];
struct Seg {
    int l,r,w;
}tr[N<<2];
void build(int p,int l,int r) {
    tr[p].l=l,tr[p].r=r;
    if(l==r) {tr[p].w=-1;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tr[p].w=-1;
}
void pushdown(int p) {
    tr[p<<1].w=tr[p<<1|1].w=tr[p].w;
    tr[p].w=-1;
}
void update(int p,int l,int r,int w) {
    if(tr[p].l>=l&&tr[p].r<=r) {
        tr[p].w=w;
        return;
    }
    if(tr[p].w!=-1) pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid) update(p<<1,l,r,w);
    if(r>mid) update(p<<1|1,l,r,w);
}
void query(int p) {
    if(tr[p].l==tr[p].r) {
        a[tr[p].l]=tr[p].w;
        return;
    }
    if(tr[p].w!=-1) pushdown(p);
    query(p<<1);
    query(p<<1|1);
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    a[0]=-1;
    while(~scanf("%d",&n)) {
        build(1,1,8000);
        for(int i=1;i<=n;i++) {
            int l,r,w;
            scanf("%d%d%d",&l,&r,&w);
            update(1,l+1,r,w);
        }
        query(1);
        for(int i=1;i<=8000;i++) {
            if(a[i]!=a[i-1]&&a[i]!=-1) cnt[a[i]]++;
        }
        for(int i=0;i<=8000;i++) {
            if(!cnt[i]) continue;
            printf("%d %d\n",i,cnt[i]);
            cnt[i]=0;
        }
        puts("");
    }
    return 0;
}