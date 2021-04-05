#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int cnt,a[N],rt[N],ls[N<<5],rs[N<<5],sum[N<<5];
vector<int> b;
int build(int l,int r) {
    int p=++cnt;
    if(l==r) return p;
    int mid=l+r>>1;
    ls[p]=build(l,mid);
    rs[p]=build(mid+1,r);
    return p;
}
int insert(int now,int l,int r,int x) {
    int p=++cnt;
    ls[p]=ls[now],rs[p]=rs[now],sum[p]=sum[now]+1;
    if(l==r) return p;
    int mid=l+r>>1;
    if(x<=mid) ls[p]=insert(ls[now],l,mid,x);
    else rs[p]=insert(rs[now],mid+1,r,x);
    return p;
}
int query(int p,int q,int l,int r,int k) {
    if(l==r) return l;
    int mid=l+r>>1;
    int lsum=sum[ls[q]]-sum[ls[p]];
    if(lsum>=k) return query(ls[p],ls[q],l,mid,k);
    else return query(rs[p],rs[q],mid+1,r,k-lsum);
}
int main() {
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    b.resize(unique(b.begin(),b.end())-b.begin());
    rt[0]=build(1,(int)b.size());
    for(int i=1;i<=n;i++) rt[i]=insert(rt[i-1],1,(int)b.size(),lower_bound(b.begin(),b.end(),a[i])-b.begin()+1);
    for(int i=1;i<=m;i++) {
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",b[query(rt[l-1],rt[r],1,(int)b.size(),k)-1]);
    }
    return 0;
}