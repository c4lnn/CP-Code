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
const int N=5e5+5;
int n,m,cnt,fa[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &a) const {
        return w<a.w;
    }
}e[N];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
LL kruskal() {
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+1+cnt);
    LL res=0;
    for(int i=1;i<=cnt;i++) {
        int tx=find(e[i].u),ty=find(e[i].v);
        if(tx==ty) continue;
        fa[tx]=ty;
        res+=e[i].w;
    }
    return -res;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[++cnt]=E(u,v,-w);
    }
    printf("%lld\n",kruskal());
    return 0;
}