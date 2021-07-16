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
//head
const int N=5e5+5;
int n,q,a[N],pre[N],nxt[N],t[N<<1],ls[N<<2],rs[N<<2],mx[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        mx[p]=pre[l];
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
void update(int p,int x,int v) {
    if(ls[p]==rs[p]) {
        mx[p]=v;
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update(p<<1,x,v);
    else update(p<<1|1,x,v);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
int query(int p,int l,int r) {
    if(l<=ls[p]&&rs[p]<=r) return mx[p];
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return max(query(p<<1,l,mid),query(p<<1|1,mid+1,r));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=t[a[i]],t[a[i]]=i;
    memset(t,0,sizeof t);
    for(int i=n;i>=1;i--) nxt[i]=t[a[i]],t[a[i]]=i;
    build(1,1,n);
    for(int i=1;i<=q;i++) {
        int o,l,r;
        cin>>o;
        if(o==1) {
            cin>>l;
            nxt[pre[l]]=nxt[l];
            pre[nxt[l]]=pre[l];
            update(1,l,0);
            update(1,nxt[l],pre[l]);
        }
        else {
            cin>>l>>r;
            cout<<(query(1,l,r)>=l?1:0)<<'\n';
        }
    }
    return 0;
}