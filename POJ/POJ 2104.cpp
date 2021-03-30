#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
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
int ls[N<<5],rs[N<<5],w[N<<5],rt[N],cnt;
VI b;
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
    ls[p]=ls[now],rs[p]=rs[now],w[p]=w[now];
    if(l==r) {w[p]++;return p;}
    int mid=l+r>>1;
    if(x<=mid) ls[p]=insert(ls[now],l,mid,x);
    else rs[p]=insert(rs[now],mid+1,r,x);
    w[p]=w[ls[p]]+w[rs[p]];
    return p;
}
int query(int p,int q,int l,int r,int k) {
    if(l==r) return l;
    int mid=l+r>>1;
    int lsum=w[ls[q]]-w[ls[p]];
    if(k<=lsum) return query(ls[p],ls[q],l,mid,k);
    else return query(rs[p],rs[q],mid+1,r,k-lsum);
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b.PB(a[i]);
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=n;i++) a[i]=lower_bound(ALL(b),a[i])-b.begin()+1;
    rt[0]=build(1,SZ(b));
    for(int i=1;i<=n;i++) rt[i]=insert(rt[i-1],1,SZ(b),a[i]);
    for(int i=1;i<=m;i++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",b[query(rt[l-1],rt[r],1,SZ(b),k)-1]);
    }
    return 0;
}