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
int in[N],st[N],id[N],pre[N],inn[N],sum,t;
struct E {
    int u,v,w,num;
    E() {}
    E(int u,int v,int w,int num):u(u),v(v),w(w),num(num) {}
};
vector<E> e;
int edmonds(int rt,int n) {
    int ret=0;
    int v,nn=n;
    while(1) {
        for(int i=1;i<=n;i++) in[i]=0x3f3f3f3f;
        for(auto x:e) {
            if(x.w<in[x.v]) {
                pre[x.v]=x.u,in[x.v]=x.w;
                inn[x.v]=x.u;
            }
        }
        t=0x3f3f3f3f;
        for(int i=1;i<=n;i++) if(inn[i]==rt) {
            for(auto x:e) if(x.u==rt&&x.v==i&&in[x.v]==x.w) t=min(t,x.num);
        }
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
    int n,m;
    while(cin>>n>>m) {
        e.clear();
        sum=0;
        for(int i=1;i<=m;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            if(u==v) continue;
            e.EB(u+1,v+1,w,0);
            sum+=w;
        }
        ++sum;
        for(int i=1;i<=n;i++) e.EB(n+1,i,sum,i);
        int res=edmonds(n+1,n+1);
        if(res==-1||res>=2*sum) cout<<"impossible"<<'\n'<<'\n';
        else cout<<res-sum<<' '<<t-1<<'\n'<<'\n';
    }
    return 0;
}