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
const int N=1e5+5;
int ls[N<<2],rs[N<<2],mn[N<<2],laz[N<<2];
struct O {
    int l,r,v;
    O() {}
    O(int l,int r,int v):l(l),r(r),v(v) {}
};
vector<O> o[N];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushdown(int p) {
    if(laz[p]) {
        mn[p<<1]+=laz[p],mn[p<<1|1]+=laz[p];
        laz[p<<1]+=laz[p],laz[p<<1|1]+=laz[p];
        laz[p]=0;
    }
}
void update(int p,int l,int r,int v) {
    if(l>r) return;
    if(ls[p]>=l&&rs[p]<=r) {
        mn[p]+=v;
        laz[p]+=v;
        return;
    }
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
int query(int p,int l,int r) {
    if(l==r) return l;
    pushdown(p);
    int mid=l+r>>1;
    if(!mn[p<<1]) return query(p<<1,l,mid);
    return query(p<<1|1,mid+1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++) {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        --x2,--y2;
        if(x2-x1>=d) x1=0,x2=d-1;
        if(y2-y1>=d) y1=0,y2=d-1;
        x1=(x1%d+d)%d,x2=(x2%d+d)%d;
        y1=(y1%d+d)%d,y2=(y2%d+d)%d;
        if(x1<=x2) {
            if(y1<=y2) {
                o[x1].EB(y1,y2,1);
                o[x2+1].EB(y1,y2,-1);
            }
            else if(y1>y2) {
                o[x1].EB(y1,d-1,1);
                o[x2+1].EB(y1,d-1,-1);
                o[x1].EB(0,y2,1);
                o[x2+1].EB(0,y2,-1);
            }
        }
        else if(x1>x2) {
            if(y1<=y2) {
                o[x1].EB(y1,y2,1);
                o[0].EB(y1,y2,1);
                o[x2+1].EB(y1,y2,-1);
            }
            else if(y1>y2) {
                o[x1].EB(y1,d-1,1);
                o[x1].EB(0,y2,1);
                o[0].EB(y1,d-1,1);
                o[0].EB(0,y2,1);
                o[x2+1].EB(y1,d-1,-1);
                o[x2+1].EB(0,y2,-1);
            }
        }
    }
    build(1,0,d-1);
    for(int i=0;i<d;i++) {
        for(auto x:o[i]) update(1,x.l,x.r,x.v);
        if(!mn[1]) {
            cout<<"YES"<<'\n';
            cout<<i<<' '<<query(1,0,d-1)<<'\n';
            return 0;
        }
    }
    cout<<"NO"<<'\n';
    return 0;
}