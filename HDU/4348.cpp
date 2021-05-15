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
int n,m,cnt,rt[N],ls[N*40],rs[N*40];
LL a[N],w[N*40],add[N*40];
int build(int l,int r) {
    int p=++cnt;
    add[p]=0;
    if(l==r) {w[p]=a[l];return p;}
    int mid=l+r>>1;
    ls[p]=build(l,mid);
    rs[p]=build(mid+1,r);
    w[p]=w[ls[p]]+w[rs[p]];
    return p;
}
int update(int now,int lc,int rc,int l,int r,LL x) {
    int p=++cnt;
    ls[p]=ls[now],rs[p]=rs[now],w[p]=w[now],add[p]=add[now];
    w[p]+=(min(rc,r)-max(lc,l)+1)*x;
    if(l<=lc&&rc<=r) {
        add[p]+=x;
        return p;
    }
    int mid=lc+rc>>1;
    if(l<=mid) ls[p]=update(ls[now],lc,mid,l,r,x);
    if(r>mid) rs[p]=update(rs[now],mid+1,rc,l,r,x);
    return p;
}
LL query(int p,int lc,int rc,int l,int r) {
    if(l<=lc&&rc<=r) {return w[p];}
    int mid=lc+rc>>1;
    LL ret=(r-l+1)*add[p];
    if(r<=mid) return ret+query(ls[p],lc,mid,l,r);
    if(l>mid) return ret+query(rs[p],mid+1,rc,l,r);
    return ret+query(ls[p],lc,mid,l,mid)+query(rs[p],mid+1,rc,mid+1,r);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        cnt=0;
        rt[0]=build(1,n);
        int t=0;
        while(m--) {
            char c;
            scanf(" %c",&c);
            if(c=='C') {
                int l,r,d;
                scanf("%d%d%lld",&l,&r,&d);
                ++t;
                rt[t]=update(rt[t-1],1,n,l,r,d);
            }
            else if(c=='Q') {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(rt[t],1,n,l,r));
            }
            else if(c=='H') {
                int l,r,t1;
                scanf("%d%d%d",&l,&r,&t1);
                printf("%lld\n",query(rt[t1],1,n,l,r));
            }
            else if(c=='B'){
                scanf("%d",&t);
            }
        }
    }
    return 0;
}