#include <iostream>
using namespace std;
const int N=5e4+5;
int ls[N<<2],rs[N<<2],sum[N<<2],lsum[N<<2],rsum[N<<2],f[N<<2];
void push_up(int p) {
    sum[p]=max(max(sum[p<<1],sum[p<<1|1]),rsum[p<<1]+lsum[p<<1|1]);
    lsum[p]=lsum[p<<1]+(lsum[p<<1]==rs[p<<1]-ls[p<<1]+1?lsum[p<<1|1]:0);
    rsum[p]=rsum[p<<1|1]+(rsum[p<<1|1]==rs[p<<1|1]-ls[p<<1|1]+1?rsum[p<<1]:0);
}
void push_down(int p) {
    if(f[p]==1) {
        sum[p<<1]=lsum[p<<1]=rsum[p<<1]=rs[p<<1]-ls[p<<1]+1;
        sum[p<<1|1]=lsum[p<<1|1]=rsum[p<<1|1]=rs[p<<1|1]-ls[p<<1|1]+1;
        f[p<<1]=f[p<<1|1]=1;
        f[p]=0;
    }
    else if(f[p]==-1) {
        sum[p<<1]=lsum[p<<1]=rsum[p<<1]=0;
        sum[p<<1|1]=lsum[p<<1|1]=rsum[p<<1|1]=0;
        f[p<<1]=f[p<<1|1]=-1;
        f[p]=0;
    }
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        sum[p]=lsum[p]=rsum[p]=1;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    sum[p]=lsum[p]=rsum[p]=rs[p]-ls[p]+1;
}
void update(int p,int l,int r,int t) {
    if(ls[p]>=l&&rs[p]<=r) {
        if(t==1) sum[p]=lsum[p]=rsum[p]=rs[p]-ls[p]+1;
        else sum[p]=lsum[p]=rsum[p]=0;
        f[p]=t;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,t);
    if(r>mid) update(p<<1|1,l,r,t);
    push_up(p);
}
int query(int p,int k) {
    if(ls[p]==rs[p]) return ls[p];
    push_down(p);
    if(sum[p<<1]>=k) return query(p<<1,k);
    else if(rsum[p<<1]+lsum[p<<1|1]>=k) return rs[p<<1]-rsum[p<<1]+1;
    else if(sum[p<<1|1]>=k) return query(p<<1|1,k);
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=m;i++) {
        int o;cin>>o;
        if(o==1) {
            int k;cin>>k;
            int pos=query(1,k);
            cout<<pos<<'\n';
            if(pos) update(1,pos,pos+k-1,-1);
        }
        else {
            int l,r;cin>>l>>r;
            update(1,l,l+r-1,1);
        }
    }
    return 0;
}