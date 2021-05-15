#include <cstdio>
#include <algorithm>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int n,m,a[N];
int ls[N<<5],rs[N<<5],sum[N<<5],rt[N],cnt;
VI b;
void update(int &p,int q,int l,int r,int x) {
    p=++cnt;
    ls[p]=ls[q],rs[p]=rs[q],sum[p]=sum[q]+1;
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) update(ls[p],ls[q],l,mid,x);
    else update(rs[p],rs[q],mid+1,r,x);
}
int query(int p,int q,int l,int r,int k) {
    if(l==r) return l;
    int mid=l+r>>1;
    int lsum=sum[ls[q]]-sum[ls[p]];
    if(k<=lsum) return query(ls[p],ls[q],l,mid,k);
    else return query(rs[p],rs[q],mid+1,r,k-lsum);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b.PB(a[i]);
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=n;i++) a[i]=lower_bound(ALL(b),a[i])-b.begin()+1;
    for(int i=1;i<=n;i++) update(rt[i],rt[i-1],1,SZ(b),a[i]);
    for(int i=1;i<=m;i++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",b[query(rt[l-1],rt[r],1,SZ(b),k)-1]);
    }
    return 0;
}