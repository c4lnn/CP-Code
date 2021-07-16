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
const int M=3e4+5;
const int N=205;
int n,fa[N],ls[M<<2],rs[M<<2],a[M<<2][N],res[N],pre[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
}e[M];
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void push_up(int *t,int *t1,int *t2) {
    for(int i=1;i<=n;i++) fa[i]=i;
    int i=1,j=1,cnt=0;
    while(t1[i]||t2[j]) {
        int x=t1[i],y=t2[j];
        if(!y||x&&y&&e[x].w<e[y].w) {
            ++i;
            int tu=find(e[x].u),tv=find(e[x].v);
            if(tu==tv) continue;
            fa[tu]=tv;
            t[++cnt]=x;
        }
        else if(!x||x&&y&&e[x].w>=e[y].w) {
            ++j;
            int tu=find(e[y].u),tv=find(e[y].v);
            if(tu==tv) continue;
            fa[tu]=tv;
            t[++cnt]=y;
        }
    }
    t[++cnt]=0;
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {a[p][1]=l;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push_up(a[p],a[p<<1],a[p<<1|1]);
}
void update(int p,int x) {
    if(ls[p]==rs[p]) {a[p][1]=x;return;}
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update(p<<1,x);
    else update(p<<1|1,x);
    push_up(a[p],a[p<<1],a[p<<1|1]);
}
void query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) {
        push_up(res,pre,a[p]);
        for(int i=1;;i++) {
            pre[i]=res[i];
            if(!res[i]) break;
        }
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) query(p<<1,l,r);
    if(r>mid) query(p<<1|1,l,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    build(1,1,m);
    for(int i=1;i<=q;i++) {
        int o;
        cin>>o;
        if(o==1) {
            int x,y,z,t;
            cin>>x>>y>>z>>t;
            e[x]=E(y,z,t);
            update(1,x);
        }
        else {
            int l,r;
            cin>>l>>r;
            for(int i=1;pre[i];i++) pre[i]=0;
            query(1,l,r);
            int sum=0,tot=0;
            for(int i=1;res[i];i++) ++tot,sum+=e[res[i]].w;
            if(tot==n-1) cout<<sum<<'\n';
            else cout<<"Impossible"<<'\n';
        }
    }
    return 0;
}