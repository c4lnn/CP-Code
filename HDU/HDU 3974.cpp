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
const int N=5e4+5;
int n,m,q,rt,cnt,dfn[N],sz[N];
int ls[N<<2],rs[N<<2],w[N<<2];
bool st[N];
VI g[N];
void dfs(int u,int fa) {
    sz[u]=1;
    dfn[u]=++cnt;
    for(auto v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {w[p]=-1;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void update(int p,int l,int r,int v) {
    if(ls[p]==rs[p]) {w[p]=v;return;}
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
}
int query(int p,int x) {
    if(ls[p]==rs[p]) return w[p];
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) return query(p<<1,x);
    else return query(p<<1|1,x);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        printf("Case #%d:\n",cs);
        cnt=0;
        for(int i=1;i<=n;i++) g[i].clear(),st[i]=false;
        scanf("%d",&n);
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            g[v].PB(u);
            st[u]=true;
        }
        for(int i=1;i<=n;i++) if(!st[i]) {rt=i;break;}
        dfs(rt,0);
        build(1,1,n);
        scanf("%d",&q);
        for(int i=1;i<=q;i++) {
            char c;
            scanf(" %c",&c);
            if(c=='T') {
                int x,k;
                scanf("%d%d",&x,&k);
                update(1,dfn[x],dfn[x]+sz[x]-1,k);
            }
            else {
                int x;
                scanf("%d",&x);
                printf("%d\n",query(1,dfn[x]));
            }
        }
    }
    return 0;
}