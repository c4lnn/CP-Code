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
const int MOD=1e4+7;
const int N=1e5+5;
int n,m,w[N<<2][4],add[N<<2][4],ls[N<<2],rs[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {
        w[p][1]=w[p][2]=w[p][3]=0;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    add[p][1]=add[p][3]=0;
    add[p][2]=1;
    w[p][1]=w[p][2]=w[p][3]=0;
}
void pushdown(int p) {
    if(add[p][3]) {
        w[p<<1][1]=(rs[p<<1]-ls[p<<1]+1)*add[p][3]%MOD;
        w[p<<1][2]=(rs[p<<1]-ls[p<<1]+1)*add[p][3]%MOD*add[p][3]%MOD;
        w[p<<1][3]=(rs[p<<1]-ls[p<<1]+1)*add[p][3]%MOD*add[p][3]%MOD*add[p][3]%MOD;
        w[p<<1|1][1]=(rs[p<<1|1]-ls[p<<1|1]+1)*add[p][3]%MOD;
        w[p<<1|1][2]=(rs[p<<1|1]-ls[p<<1|1]+1)*add[p][3]%MOD*add[p][3]%MOD;
        w[p<<1|1][3]=(rs[p<<1|1]-ls[p<<1|1]+1)*add[p][3]%MOD*add[p][3]%MOD*add[p][3]%MOD;
        add[p<<1][3]=add[p<<1|1][3]=add[p][3];
        add[p][3]=add[p<<1][1]=add[p<<1|1][1]=0;
        add[p<<1][2]=add[p<<1|1][2]=1;
    }
    if(add[p][2]!=1) {
        w[p<<1][1]=w[p<<1][1]*add[p][2]%MOD;
        w[p<<1][2]=w[p<<1][2]*add[p][2]%MOD*add[p][2]%MOD;
        w[p<<1][3]=w[p<<1][3]*add[p][2]%MOD*add[p][2]%MOD*add[p][2]%MOD;
        w[p<<1|1][1]=w[p<<1|1][1]*add[p][2]%MOD;
        w[p<<1|1][2]=w[p<<1|1][2]*add[p][2]%MOD*add[p][2]%MOD;
        w[p<<1|1][3]=w[p<<1|1][3]*add[p][2]%MOD*add[p][2]%MOD*add[p][2]%MOD;
        add[p<<1][2]=add[p<<1][2]*add[p][2]%MOD;
        add[p<<1|1][2]=add[p<<1|1][2]*add[p][2]%MOD;
        add[p<<1][1]=add[p<<1][1]*add[p][2]%MOD;
        add[p<<1|1][1]=add[p<<1|1][1]*add[p][2]%MOD;
        add[p][2]=1;
    }
    if(add[p][1]) {
        w[p<<1][3]=(w[p<<1][3]+(rs[p<<1]-ls[p<<1]+1)*add[p][1]%MOD*add[p][1]%MOD*add[p][1]%MOD)%MOD;
        w[p<<1][3]=(w[p<<1][3]+3*add[p][1]%MOD*w[p<<1][2]%MOD)%MOD;
        w[p<<1][3]=(w[p<<1][3]+3*add[p][1]%MOD*add[p][1]%MOD*w[p<<1][1]%MOD)%MOD;
        w[p<<1][2]=((w[p<<1][2]+(rs[p<<1]-ls[p<<1]+1)*add[p][1]%MOD*add[p][1]%MOD)%MOD+2*add[p][1]%MOD*w[p<<1][1]%MOD)%MOD;
        w[p<<1][1]=(w[p<<1][1]+(rs[p<<1]-ls[p<<1]+1)*add[p][1]%MOD)%MOD;
        w[p<<1|1][3]=(w[p<<1|1][3]+(rs[p<<1|1]-ls[p<<1|1]+1)*add[p][1]%MOD*add[p][1]%MOD*add[p][1]%MOD)%MOD;
        w[p<<1|1][3]=(w[p<<1|1][3]+3*add[p][1]%MOD*w[p<<1|1][2]%MOD)%MOD;
        w[p<<1|1][3]=(w[p<<1|1][3]+3*add[p][1]%MOD*add[p][1]%MOD*w[p<<1|1][1]%MOD)%MOD;
        w[p<<1|1][2]=((w[p<<1|1][2]+(rs[p<<1|1]-ls[p<<1|1]+1)*add[p][1]%MOD*add[p][1]%MOD)%MOD+2*add[p][1]%MOD*w[p<<1|1][1]%MOD)%MOD;
        w[p<<1|1][1]=(w[p<<1|1][1]+(rs[p<<1|1]-ls[p<<1|1]+1)*add[p][1]%MOD)%MOD;
        add[p<<1][1]=(add[p<<1][1]+add[p][1])%MOD;
        add[p<<1|1][1]=(add[p<<1|1][1]+add[p][1])%MOD;
        add[p][1]=0;
    }
}
void update(int p,int l,int r,int t,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        int len=rs[p]-ls[p]+1;
        if(t==3) {
            w[p][1]=len*v%MOD;
            w[p][2]=len*v%MOD*v%MOD;
            w[p][3]=len*v%MOD*v%MOD*v%MOD;
            add[p][3]=v;
            add[p][1]=0;
            add[p][2]=1;
        }
        else if(t==2) {
            w[p][1]=w[p][1]*v%MOD;
            w[p][2]=w[p][2]*v%MOD*v%MOD;
            w[p][3]=w[p][3]*v%MOD*v%MOD*v%MOD;
            add[p][1]=add[p][1]*v%MOD;
            add[p][2]=add[p][2]*v%MOD;
        }
        else if(t==1) {
            w[p][3]=(w[p][3]+len*v%MOD*v%MOD*v%MOD)%MOD;
            w[p][3]=(w[p][3]+3*v%MOD*w[p][2]%MOD)%MOD;
            w[p][3]=(w[p][3]+3*v%MOD*v%MOD*w[p][1]%MOD)%MOD;
            w[p][2]=((w[p][2]+len*v%MOD*v%MOD)%MOD+2*v%MOD*w[p][1]%MOD)%MOD;
            w[p][1]=(w[p][1]+len*v%MOD)%MOD;
            add[p][1]=(add[p][1]+v)%MOD;
        }
        return;
    }
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,t,v);
    if(r>mid) update(p<<1|1,l,r,t,v);
    for(int i=1;i<=3;i++) w[p][i]=(w[p<<1][i]+w[p<<1|1][i])%MOD;
}
int query(int p,int l,int r,int t) {
    if(ls[p]>=l&&rs[p]<=r) return w[p][t];
    pushdown(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r,t);
    if(l>mid) return query(p<<1|1,l,r,t);
    return (query(p<<1,l,r,t)+query(p<<1|1,l,r,t))%MOD;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(!n&&!m) break;
        build(1,1,n);
        for(int i=1;i<=m;i++) {
            int a,l,r,c;
            scanf("%d%d%d%d",&a,&l,&r,&c);
            if(a==1) update(1,l,r,a,c);
            else if(a==2) update(1,l,r,a,c);
            else if(a==3) update(1,l,r,a,c);
            else printf("%d\n",query(1,l,r,c));
        }
    }
    return 0;
}