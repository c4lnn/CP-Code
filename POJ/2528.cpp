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
const int N=20005;
int n,a[N],b[N],res,cnt,c[N<<2];
bool st[N];
struct Seg {
    int l,r,w;
}tr[N<<3];
void build(int p,int l,int r) {
    tr[p].l=l,tr[p].r=r;
    tr[p].w=-1;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushdown(int p) {
    tr[p<<1].w=tr[p<<1|1].w=tr[p].w;
    tr[p].w=-1;
}
void update(int p,int l,int r,int w) {
    if(tr[p].l>=l&&tr[p].r<=r) {
        tr[p].w=w;
        return;
    }
    if(tr[p].w!=-1) pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid) update(p<<1,l,r,w);
    if(r>mid) update(p<<1|1,l,r,w);
}
void query(int p) {
    if(tr[p].w!=-1) {
        if(!st[tr[p].w]) res++,st[tr[p].w]=true;
        return;
    }
    if(tr[p].l==tr[p].r) return;
    query(p<<1);
    query(p<<1|1);
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        cnt=res=0;
        for(int i=1;i<=n;i++) st[i]=false;
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&a[i],&b[i]);
            c[++cnt]=a[i];
            c[++cnt]=b[i];
        }
        sort(c+1,c+1+cnt);
        cnt=unique(c+1,c+1+cnt)-c-1;
        int t=cnt;
        for(int i=1;i<=t;i++)
            if(c[i]-c[i-1]>1)
                c[++cnt]=c[i]-1;
        sort(c+1,c+1+cnt);
        int mx=0;
        for(int i=1;i<=n;i++) {
            a[i]=lower_bound(c+1,c+1+cnt,a[i])-c;
            b[i]=lower_bound(c+1,c+1+cnt,b[i])-c;
            mx=max(mx,b[i]);
        }
        build(1,1,mx);
        for(int i=1;i<=n;i++) update(1,a[i],b[i],i);
        query(1);
        printf("%d\n",res);
    }
    return 0;
}