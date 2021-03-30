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
const int N=1005;
int x[N],y[N],z[N],in[N],st[N],id[N],pre[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
};
vector<E> e;
int edmonds(int rt,int n) {
    LL ret=0;
    int v,nn=n;
    for(;;) {
        for(int i=1;i<=n;i++) in[i]=0x3f3f3f3f;
        for(auto x:e) if(x.u!=x.v&&x.w<in[x.v]) pre[x.v]=x.u,in[x.v]=x.w;
        for(int i=1;i<=n;i++) if(i!=rt&&in[i]==0x3f3f3f3f) return -1;
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
            auto &x=e[i];
            v=x.v;
            x.u=id[x.u],x.v=id[x.v];
            if(x.u!=x.v) x.w-=in[v],++i;
            else swap(x,e.back()),e.pop_back();
        }
        n=tn,rt=id[rt];
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,X,Y,Z;
    while(cin>>n>>X>>Y>>Z) {
        if(!n&&!X&&!Y&&!Z) break;
        e.clear();
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
        for(int i=1;i<=n;i++) {
            int k;
            cin>>k;
            for(int j=1;j<=k;j++) {
                int v;
                cin>>v;
                if(v==i) continue;
                e.EB(i,v,(abs(x[i]-x[v])+abs(y[i]-y[v])+abs(z[i]-z[v]))*Y+(z[i]<z[v]?Z:0));
            }
        }
        for(int i=1;i<=n;i++) e.EB(n+1,i,X*z[i]);
        cout<<edmonds(n+1,n+1)<<'\n';
    }
    return 0;
}