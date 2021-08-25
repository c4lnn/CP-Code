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
LL sum1[N<<2],sum2[N<<2],laz[N<<2];
int lowbit(int x) {
    return x&-x;
}
void push_up(int p) {
    if(tag[p<<1]&&tag[p<<1|1]) tag[p]=1;
    else tag[p]=0;
    sum1[p]=(sum1[p<<1]+sum1[p<<1|1])%MOD;
    sum2[p]=(sum2[p<<1]+sum2[p<<1|1])%MOD;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r,laz[p]=1;
    if(l==r) {
        if(!a[l]) sum1[p]=sum2[p]=0,tag[p]=1;
        else {
            tag[p]=0;
            sum2[p]=1<<(31-__builtin_clz(a[l]));
            sum1[p]=a[l]-sum2[p];
        }
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(p);
}
void push_down(int p) {
    if(laz[p]>1) {
        sum2[p<<1]=sum2[p<<1]*laz[p]%MOD;
        sum2[p<<1|1]=sum2[p<<1|1]*laz[p]%MOD;
        laz[p<<1]=laz[p<<1]*laz[p]%MOD;
        laz[p<<1|1]=laz[p<<1|1]*laz[p]%MOD;
        laz[p]=1;
    }
}
void update1(int p,int l,int r) {
    if(ls[p]==rs[p]) {
        if(sum1[p]) sum1[p]-=lowbit(sum1[p]);
        else sum2[p]=0,tag[p]=1;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid&&!tag[p<<1]) update1(p<<1,l,r);
    if(r>mid&&!tag[p<<1|1]) update1(p<<1|1,l,r);
    push_up(p);
}
void update2(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) {
        sum2[p]=sum2[p]*2%MOD;
        laz[p]=laz[p]*2%MOD;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid&&!tag[p<<1]) update2(p<<1,l,r);
    if(r>mid&&!tag[p<<1|1]) update2(p<<1|1,l,r);
    push_up(p);
}
LL query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return (sum1[p]+sum2[p])%MOD;
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return (query(p<<1,l,mid)+query(p<<1|1,mid+1,r))%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        build(1,1,n);
        int q;cin>>q;
        for(int i=1;i<=q;i++) {
            int o,l,r;cin>>o>>l>>r;
            if(o==1) cout<<query(1,l,r)<<'\n';
            else if(o==2) update1(1,l,r);
            else update2(1,l,r);
        }
    }
    return 0;
}