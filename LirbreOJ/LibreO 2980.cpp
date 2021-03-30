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
//head
const LL MOD=998244353;
const int N=2e5+5e4+5;
const int sz=3;
int ls[N<<2],rs[N<<2];
LL a[N],b[N],c[N];
struct M {
    LL a[sz][sz];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    void init() {
        clear();
        for(int i=0;i<sz;i++) a[i][i]=1;
    }
    M operator + (const M &T) const {
        M res;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                res.a[i][j]=(a[i][j]+T.a[i][j])%MOD;
        return res;
    }
    M operator * (const LL &v) const {
        M res;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++) {
                if(!a[i][j]) continue;
                res.a[i][j]=a[i][j]*v%MOD;
            }
        return res;
    }
    M operator * (const M &T) const {
        M res;
        for(int i=0;i<sz;i++)
            for(int k=0;k<sz;k++) {
                int t=a[i][k];
                if(!t) continue;
                for(int j=0;j<sz;j++) {
                    if(!T.a[k][j]) continue;
                    res.a[i][j]=(res.a[i][j]+T.a[k][j]*t%MOD)%MOD;
                }
            }
        return res;
    }
    void print() {
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                cout<<a[i][j]<<" \n"[j==sz-1];
    }
}w[N<<2],add1[N<<2],add2[N<<2],t;
void push_down(int p) {
        w[p<<1]=w[p<<1]*add1[p]+add2[p]*(rs[p<<1]-ls[p<<1]+1);
        w[p<<1|1]=w[p<<1|1]*add1[p]+add2[p]*(rs[p<<1|1]-ls[p<<1|1]+1);
        add1[p<<1]=add1[p<<1]*add1[p];
        add1[p<<1|1]=add1[p<<1|1]*add1[p];
        add2[p<<1]=add2[p<<1]*add1[p]+add2[p];
        add2[p<<1|1]=add2[p<<1|1]*add1[p]+add2[p];
        add1[p].init();
        add2[p].clear();
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        w[p].a[0][0]=a[l];
        w[p].a[0][1]=b[l];
        w[p].a[0][2]=c[l];
        add1[p].init();
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=w[p<<1]+w[p<<1|1];
    add1[p].init();
}
void update(int p,int l,int r,int op) {
    if(l<=ls[p]&&rs[p]<=r) {
        if(!op) w[p]=w[p]*t,add1[p]=add1[p]*t,add2[p]=add2[p]*t;
        else w[p]=w[p]+t*(rs[p]-ls[p]+1),add2[p]=add2[p]+t;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,op);
    if(r>mid) update(p<<1|1,l,r,op);
    w[p]=w[p<<1]+w[p<<1|1];
}
M query(int p,int l,int r) {
    if(l<=ls[p]&&rs[p]<=r) {
        return w[p];
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,mid)+query(p<<1|1,mid+1,r);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    //freopen("E:/OneDrive/IO/out.txt","w",stdout);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    build(1,1,n);
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int op,l,r;scanf("%d%d%d",&op,&l,&r);
        if(op<=3) {
            t.init();
            if(op==1) t.a[1][0]=1;
            else if(op==2) t.a[2][1]=1;
            else if(op==3) t.a[0][2]=1;
            update(1,l,r,0);
        }
        else if(op<=6) {
            LL v;scanf("%lld",&v);
            if(op==4) t.clear(),t.a[0][0]=v,update(1,l,r,1);
            else if(op==5) t.init(),t.a[1][1]=v,update(1,l,r,0);
            else {
                t.clear();
                t.a[0][0]=t.a[1][1]=1;
                update(1,l,r,0);
                t.a[0][0]=t.a[1][1]=0;
                t.a[0][2]=v;
                update(1,l,r,1);
            }
        }
        else {
            M res=query(1,l,r);
            for(int j=0;j<3;j++) printf("%lld%c",res.a[0][j]," \n"[j==2]);
        }
    }
    return 0;
}