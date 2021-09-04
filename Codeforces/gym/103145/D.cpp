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
const LL MOD=998244353;
const int N=1e5+5;
int a[N],ls[N<<2],rs[N<<2],tag[N<<2];
LL sum[N<<2],laz[N<<2];
int lowbit(int x) {
    return x&-x;
}
void push_up(int p) {
    sum[p]=(sum[p<<1]+sum[p<<1|1])%MOD;
    tag[p]=tag[p<<1]&tag[p<<1|1];
}
void push_down(int p) {
    if(laz[p]>1) {
        sum[p<<1]=sum[p<<1]*laz[p]%MOD;
        sum[p<<1|1]=sum[p<<1|1]*laz[p]%MOD;
        laz[p<<1]=laz[p<<1]*laz[p]%MOD;
        laz[p<<1|1]=laz[p<<1|1]*laz[p]%MOD;
        laz[p]=1;
    }
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r,tag[p]=0,laz[p]=1;
    if(l==r) {
        sum[p]=a[l];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(p);
}
void update(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r&&tag[p]) {
        sum[p]=(sum[p]*2)%MOD;
        laz[p]=(laz[p]*2)%MOD;
        return;
    }
    if(ls[p]==rs[p]) {
        sum[p]+=lowbit(sum[p]);
        if(sum[p]==1<<30) tag[p]=1;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r);
    if(r>mid) update(p<<1|1,l,r);
    push_up(p);
}
LL query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return sum[p]%MOD;
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r)%MOD;
    if(l>mid) return query(p<<1|1,l,r)%MOD;
    return (query(p<<1,l,r)+query(p<<1|1,l,r))%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        build(1,1,n);
        int m;cin>>m;
        for(int i=1;i<=m;i++) {
            int o,l,r;cin>>o>>l>>r;
            if(o==1) update(1,l,r);
            else cout<<query(1,l,r)<<'\n';
        }
    }
    return 0;
}