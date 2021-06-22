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
const int N=5e4+5;
int n,k,rt,cnt,sz[N],mx[N],dist[N],a[N],tot[N];
LL res;
bool st[N];
VI g[N];
void get_rt(int u,int fa,int sum) {
    sz[u]=1;
    mx[u]=0;
    for(auto v:g[u]) if(v!=fa&&!st[v]) {
        get_rt(v,u,sum);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
    mx[u]=max(mx[u],sum-sz[u]);
    if(mx[u]<mx[rt]) rt=u;
}
void get_dist(int u,int fa) {
    if(dist[u]>k) return;
    a[++cnt]=dist[u];
    for(auto v:g[u]) if(v!=fa&&!st[v]) {
        dist[v]=dist[u]+1;
        get_dist(v,u);
    }
}
LL calc(int u,int t) {
    dist[u]=t;
    cnt=0;
    get_dist(u,0);
    for(int i=0;i<=k;i++) tot[i]=0;
    for(int i=1;i<=cnt;i++) ++tot[a[i]];
    LL ret=0;
    for(int i=1;i<=cnt;i++) {
        --tot[a[i]];
        ret+=tot[k-a[i]];
    }
    return ret;
}
void divide(int u) {
    mx[rt=0]=INT_MAX;
    get_rt(u,0,sz[u]);
    u=rt;
    st[u]=true;
    res+=calc(u,0);
    for(auto v:g[u]) if(!st[v]) {
        res-=calc(v,1);
        divide(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    sz[1]=n;divide(1);
    cout<<res<<'\n';
    return 0;
}