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
int n,ls[N<<2],rs[N<<2],cover[N<<2],w1[N<<2],w2[N<<2],w3[N<<2];
VI a,b;
struct R {
    int x1,y1,z1,x2,y2,z2;
    R() {}
    R(int x1,int y1,int z1,int x2,int y2,int z2):x1(x1),y1(y1),z1(z1),x2(x2),y2(y2),z2(z2) {}
}r[N];
struct RR {
    int x,y1,y2,v;
    RR() {}
    RR(int x,int y1,int y2,int v):x(x),y1(y1),y2(y2),v(v) {}
    bool operator < (const RR &a) const {
        return x<a.x;
    }
};
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r,cover[p]=w1[p]=w2[p]=w3[p]=0;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void push_up(int p) {
    if(cover[p]) {
        w1[p]=a[rs[p]]-a[ls[p]-1];
        if(cover[p]==1) {
            if(ls[p]!=rs[p]) {
                w2[p]=w1[p<<1]+w1[p<<1|1];
                w3[p]=w2[p<<1]+w2[p<<1|1];
            }
            else w2[p]=w3[p]=0;
        }
        else if(cover[p]==2) {
            w2[p]=w1[p];
            if(ls[p]!=rs[p]) w3[p]=w1[p<<1]+w1[p<<1|1];
            else w3[p]=0;
        }
        else w3[p]=w2[p]=w1[p];
    }
    else if(ls[p]==rs[p]) w1[p]=w2[p]=w3[p]=0;
    else {
        w1[p]=w1[p<<1]+w1[p<<1|1];
        w2[p]=w2[p<<1]+w2[p<<1|1];
        w3[p]=w3[p<<1]+w3[p<<1|1];
    }
}
void update(int p,int l,int r,int v,int q) {
    if(l<=ls[p]&&rs[p]<=r) {
        cover[p]+=v;
        push_up(p);
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v,q);
    if(r>mid) update(p<<1|1,l,r,v,q);
    push_up(p);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        a.clear(),b.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            int x1,y1,z1,x2,y2,z2;
            scanf("%d%d%d%d%d%d",&y1,&x1,&z1,&y2,&x2,&z2);
            a.PB(y1),a.PB(y2);
            b.PB(z1),b.PB(z2);
            r[i]=R(x1,y1,z1,x2,y2,z2);
        }
        sort(ALL(a)),sort(ALL(b));
        a.resize(unique(ALL(a))-a.begin());
        b.resize(unique(ALL(b))-b.begin());
        for(int i=1;i<=n;i++) {
            r[i].y1=lower_bound(ALL(a),r[i].y1)-a.begin()+1;
            r[i].y2=lower_bound(ALL(a),r[i].y2)-a.begin()+1;
        }
        LL res=0;
        for(int i=0;i<SZ(b)-1;i++) {
            vector<RR> t;
            for(int j=1;j<=n;j++) {
                if(r[j].z1<=b[i]&&r[j].z2>b[i]) {
                    t.EB(r[j].x1,r[j].y1,r[j].y2,1);
                    t.EB(r[j].x2,r[j].y1,r[j].y2,-1);
                }
            }
            sort(ALL(t));
            build(1,1,SZ(a)-1);
            LL sum=0;
            for(int j=0;j<SZ(t)-1;j++) {
                update(1,t[j].y1,t[j].y2-1,t[j].v,j);
                sum+=1ll*w3[1]*(t[j+1].x-t[j].x);
            }
            res+=sum*(b[i+1]-b[i]);
        }
        printf("Case %d: %lld\n",cs,res);
    }
    return 0;
}