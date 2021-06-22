#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=1e4+5;
int res,n,k,cnt,rt,sz[N],mx[N],dist[N],tot[N],a[N],b[N];
bool st[N];
VPII g[N];
void init(int n) {
    for(int i=1;i<=n;i++) {
        g[i].clear();
        st[i]=false;
        tot[i]=0;
    }
    res=0;
}
void get_rt(int u,int fa,int sum) {
    sz[u]=1;
    mx[u]=0;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI;
        if(v==fa||st[v]) continue;
        get_rt(v,u,sum);
        mx[u]=max(mx[u],sz[v]);
        sz[u]+=sz[v];
    }
    mx[u]=max(mx[u],sum-sz[u]);
    if(mx[u]<mx[rt]) rt=u;
}
void get_dist(int u,int fa) {
    a[++cnt]=u;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI,w=g[u][i].SE;
        if(st[v]||v==fa) continue;
        dist[v]=dist[u]+w;
        ++tot[b[v]=b[u]];
        get_dist(v,u);
    }
}
bool cmp(int a,int b) {
    return dist[a]<dist[b];
}
int calc(int u) {
    int ret=0;
    dist[u]=0;
    cnt=0;
    tot[b[u]=u]=0;
    a[++cnt]=u;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI,w=g[u][i].SE;
        if(st[v]) continue;
        dist[v]=w;
        ++tot[b[v]=v];
        get_dist(v,v);
    }
    sort(a+1,a+1+cnt,cmp);
    int l=1,r=cnt;
    while(l<r) {
        if(dist[a[l]]+dist[a[r]]<=k) {
            ret+=r-l-tot[b[a[l]]];
            --tot[b[a[++l]]];
        }
        else --tot[b[a[r--]]];
    }
    return ret;
}
void divide(int u) {
    rt=0,mx[rt]=INT_MAX;
    get_rt(u,0,sz[u]);
    u=rt;
    st[u]=true;
    res+=calc(u);
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i].FI,w=g[u][i].SE;
        if(st[v]) continue;
        divide(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>k) {
        if(!n&&!k) break;
        init(n);
        for(int i=1;i<n;i++) {
            int u,v,w;cin>>u>>v>>w;
            g[u].PB(MP(v,w));
            g[v].PB(MP(u,w));
        }
        divide(1);
        cout<<res<<'\n';
    }
    return 0;
}