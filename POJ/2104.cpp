#include <cstdio>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
int ls[N<<5],rs[N<<5],sum[N<<5],rt[N],cnt;
void update(int &p,int q,int L,int R,int x) {
    p=++cnt;
    ls[p]=ls[q],rs[p]=rs[q],sum[p]=sum[q]+1;
    if(L==R) return;
    int mid=L+R>>1;
    if(x<=mid) update(ls[p],ls[q],L,mid,x);
    else update(rs[p],rs[q],mid+1,R,x);
}
int query(int p,int q,int L,int R,int k) {
    if(L==R) return L;
    int mid=L+R>>1;
    int lsum=sum[ls[q]]-sum[ls[p]];
    if(k<=lsum) return query(ls[p],ls[q],L,mid,k);
    else return query(rs[p],rs[q],mid+1,R,k-lsum);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) update(rt[i],rt[i-1],-1e9,1e9,a[i]);
    for(int i=1;i<=m;i++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",query(rt[l-1],rt[r],-1e9,1e9,k));
    }
    return 0;
}