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
const int N=1e5+5;
struct Node {
    int x,y,w;
    Node() {}
    Node(int x,int y,int w):x(x),y(y),w(w) {}
    bool operator < (const Node &a) const {
        return x<a.x||x==a.x&&y>a.y;
    }
}v[N];
int n;
VI a;
struct seg {
    int l,r;
    int w;
}tr[N*4];
void build(int p,int l,int r) {
    tr[p].l=l,tr[p].r=r;
    if(l==r) {tr[p].w=0;return;}
    int mid=l+r>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tr[p].w=0;
}
void update(int p,int x,int v) {
    if(tr[p].l==tr[p].r) {
        tr[p].w=max(tr[p].w,v);
        return;
    }
    int mid=tr[p].l+tr[p].r>>1;
    if(x<=mid) update(p*2,x,v);
    else update(p*2+1,x,v);
    tr[p].w=max(tr[p*2].w,tr[p*2+1].w);
}
int query(int p,int l,int r) {
    if(tr[p].l>=l&&tr[p].r<=r) return tr[p].w;
    int mid=tr[p].l+tr[p].r>>1;
    if(r<=mid) return query(p*2,l,r);
    if(l>mid) return query(p*2+1,l,r);
    return max(query(p*2,l,r),query(p*2+1,l,r));
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        a.clear();
        for(int i=1;i<=n;i++) {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            v[i]=Node(x,y,w);
            a.PB(y);
        }
        a.PB(0);
        sort(ALL(a));
        a.resize(unique(ALL(a))-a.begin());
        for(int i=1;i<=n;i++) v[i].y=lower_bound(ALL(a),v[i].y)-a.begin()+1;
        sort(v+1,v+1+n);
        build(1,1,SZ(a));
        int res=0;
        for(int i=1;i<=n;i++) {
            if(v[i].y==1) continue;
            int t=query(1,1,v[i].y-1)+v[i].w;
            update(1,v[i].y,t);
            res=max(res,t);
        }
        printf("%d\n",res);
    }
    return 0;
}