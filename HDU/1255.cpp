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
const int N=2005;
vector<DB> a;
struct R {
    DB x,y1,y2;
    int w;
    R() {}
    R(DB x,DB y1,DB y2,int w):x(x),y1(y1),y2(y2),w(w) {}
    bool operator < (const R &a) const {
        return x<a.x;
    }
}o[N<<1];
int n,ls[N<<2],rs[N<<2],cover[N<<2];
DB w1[N<<2],w2[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        cover[p]=0;
        w1[p]=w2[p]=0;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    cover[p]=0;
    w1[p]=w2[p]=0;
}
void push_up(int p) {
    if(cover[p]) {
        w1[p]=a[rs[p]]-a[ls[p]-1];
        if(cover[p]==1) {
            if(ls[p]==rs[p]) w2[p]=0;
            else w2[p]=w1[p<<1]+w1[p<<1|1];
        }
        else w2[p]=w1[p];
    }
    else if(ls[p]==rs[p]) w1[p]=w2[p]=0;
    else {
        w1[p]=w1[p<<1]+w1[p<<1|1];
        w2[p]=w2[p<<1]+w2[p<<1|1];
    }
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        cover[p]+=v;
        push_up(p);
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    push_up(p);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        a.clear();
        DB x1,x2,y1,y2;
        int cnt=0;
        for(int i=1;i<=n;i++) {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            o[++cnt]=(R(x1,y1,y2,1));
            o[++cnt]=(R(x2,y1,y2,-1));
            a.PB(y1),a.PB(y2);
        }
        sort(ALL(a));
        a.resize(unique(ALL(a))-a.begin());
        for(int i=1;i<=cnt;i++) {
            o[i].y1=lower_bound(ALL(a),o[i].y1)-a.begin()+1;
            o[i].y2=lower_bound(ALL(a),o[i].y2)-a.begin()+1;
        }
        sort(o+1,o+1+cnt);
        build(1,1,SZ(a)-1);
        DB res=0;
        for(int i=1;i<=cnt;i++) {
            res+=w2[1]*(o[i].x-o[i-1].x);
            update(1,o[i].y1,o[i].y2-1,o[i].w);
        }
        printf("%.2f\n",res);
    }
    return 0;
}