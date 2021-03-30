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
const int N=5e4+5;
int n,m,w[N<<2],ls[N<<2],rs[N<<2],add[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {w[p]=0,add[p]=-1;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=0;
    add[p]=-1;
}
void pushdown(int p) {
    if(add[p]==-1) return;
    w[p<<1]=(rs[p<<1]-ls[p<<1]+1)*add[p];
    w[p<<1|1]=(rs[p<<1|1]-ls[p<<1|1]+1)*add[p];
    add[p<<1]=add[p<<1|1]=add[p];
    add[p]=-1;
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        w[p]=(rs[p]-ls[p]+1)*v;
        add[p]=v;
        return;
    }
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    w[p]=w[p<<1]+w[p<<1|1];
}
int query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return w[p];
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
int solve(int l,int x) {
    int t=l,r=n;
    while(l<r) {
        int mid=l+r>>1;
        if(mid-t+1-query(1,t,mid)>=x) r=mid;
        else l=mid+1;
    }
    return l;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        build(1,1,n);
        for(int i=1;i<=m;i++) {
            int k;
            scanf("%d",&k);
            if(k==1) {
                int a,x;
                scanf("%d%d",&a,&x);
                ++a;
                int cnt=n-a+1-query(1,a,n);
                if(!cnt) {puts("Can not put any one.");continue;}
                int l=solve(a,1);
                int r=solve(l,min(cnt,x));
                printf("%d %d\n",l-1,r-1);
                update(1,l,r,1);
            }
            else {
                int l,r;
                scanf("%d%d",&l,&r);
                ++l,++r;
                printf("%d\n",query(1,l,r));
                update(1,l,r,0);
            }
        }
        puts("");
    }
    return 0;
}