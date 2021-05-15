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
const int N=205;
int n,ls[N<<2],rs[N<<2],cover[N<<2];
DB len[N<<2];
struct R {
    DB x,y1,y2;
    int w;
    R() {}
    R(DB x,DB y1,DB y2,int w):x(x),y1(y1),y2(y2),w(w) {}
    bool operator < (const R &a) const {
        return x<a.x;
    }
};
vector<DB> a;
vector<R> o;
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        cover[p]=0;
        len[p]=0;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    cover[p]=0;
    len[p]=0;
}
void push_up(int p) {
    if(cover[p]) len[p]=a[rs[p]]-a[ls[p]-1];
    else if(ls[p]==rs[p]) len[p]=0;
    else len[p]=len[p<<1]+len[p<<1|1];
}
void update(int p,int l,int r,int w) {
    if(ls[p]>=l&&rs[p]<=r) {
        cover[p]+=w;
        push_up(p);
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,w);
    if(r>mid) update(p<<1|1,l,r,w);
    push_up(p);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int cs=0;
    while(~scanf("%d",&n)&&n) {
        o.clear(),a.clear();
        for(int i=1;i<=n;i++) {
            DB x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            o.EB(x1,y1,y2,1),o.EB(x2,y1,y2,-1);
            a.PB(y1),a.PB(y2);
        }
        sort(ALL(a));
        a.resize(unique(ALL(a))-a.begin());
        for(int i=0;i<SZ(o);i++) {
            o[i].y1=lower_bound(ALL(a),o[i].y1)-a.begin()+1;
            o[i].y2=lower_bound(ALL(a),o[i].y2)-a.begin()+1;
        }
        sort(ALL(o));
        build(1,1,SZ(a)-1);
        DB res=0;
        for(int i=0;i<SZ(o);i++) {
            if(i>=1) res+=len[1]*(o[i].x-o[i-1].x);
            update(1,o[i].y1,o[i].y2-1,o[i].w);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",++cs,res);
    }
    return 0;
}