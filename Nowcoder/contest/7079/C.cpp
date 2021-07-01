#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
const int M=5e5+5;
unsigned int SA, SB, SC;
int n, m, q, LIM;
int u[M],v[M],w[M],L[M];
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void gen(){
    scanf("%d%d%d%u%u%u%d", &n, &m, &q, &SA, &SB, &SC, &LIM);
    for(int i = 1; i <= m; i++){
        u[i] = rng61() % n + 1;
        v[i] = rng61() % n + 1;
        w[i] = rng61() % LIM;
    }
    for(int i = 1; i <= q; i++){
        L[i] = rng61() % LIM;
    }
}
int fa[N];
LL sz[N],now;
struct E {
    int u,v,w,opt;
    E() {}
    E(int u,int v,int w,int opt):u(u),v(v),w(w),opt(opt) {}
    bool operator < (const E &a) const {
        return w<a.w||w==a.w&&opt<a.opt;
    }
};
vector<E> e;
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return;
    now+=sz[tx]*sz[ty];
    fa[tx]=ty;
    sz[ty]+=sz[tx];
}
int main() {
    //freopen("D:/Program Files (x86)/Sublime Text 3/in.txt","r",stdin);
    gen();
    for(int i=1;i<=m;i++) e.PB(E(u[i],v[i],w[i],1));
    for(int i=1;i<=q;i++) e.PB(E(0,0,L[i],2));
    sort(ALL(e));
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    LL res=0;
    for(int i=0;i<e.size();i++) {
        if(e[i].opt==1) merge(e[i].u,e[i].v);
        else res^=now;
    }
    printf("%lld\n",res);
    return 0;
}