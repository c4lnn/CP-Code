#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define SZ(x) (int)(x).size()
#define PB push_back
using namespace std;
typedef double DB;
const int N=105;
DB x[N],y[N];
int n,m;
DB in[N<<1];
int st[N<<1],id[N<<1],pre[N<<1];
struct E {
    int u,v;
    DB w;
    E() {}
    E(int u,int v,DB w):u(u),v(v),w(w) {}
};
vector<E> e;
void edmonds(int rt,int n) {
    DB ret=0;
    int v,nn=n;
    while(1) {
        for(int i=1;i<=n;i++) in[i]=1e9;
        for(int i=0;i<SZ(e);i++) {
            E &x=e[i];
            if(x.u!=x.v&&x.w<in[x.v]) pre[x.v]=x.u,in[x.v]=x.w;
        }
        for(int i=1;i<=n;i++) if(i!=rt&&in[i]==1e9) {puts("poor snoopy");return;}
        int tn=0;
        for(int i=1;i<=nn;i++) id[i]=st[i]=-1;
        in[rt]=0;
        for(int i=1;i<=n;i++) {
            ret+=in[v=i];
            while(st[v]!=i&&id[v]==-1&&v!=rt) st[v]=i,v=pre[v];
            if(v!=rt&&id[v]==-1) {
                ++tn;
                for(int u=pre[v];u!=v;u=pre[u]) id[u]=tn;
                id[v]=tn;
            }
        }
        if(!tn) break;
        for(int i=1;i<=n;i++) if(id[i]==-1) id[i]=++tn;
        for(int i=0;i<SZ(e);) {
            E &x=e[i];
            v=x.v;
            x.u=id[x.u],x.v=id[x.v];
            if(x.u!=x.v) x.w-=in[v],++i;
            else swap(x,e.back()),e.pop_back();
        }
        n=tn,rt=id[rt];
    }
    printf("%.2f\n",ret);
}
DB calc(DB ax,DB ay,DB bx,DB by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
int main() {
    while(~scanf("%d%d",&n,&m)) {
        e.clear();
        for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            e.PB(E(u,v,calc(x[u],y[u],x[v],y[v])));
        }
        edmonds(1,n);
    }
    return 0;
}