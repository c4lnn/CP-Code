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
const int N=1e5+5;
VI g[N];
int w[N],sz[N],son[N],cnt[N],mx,sn;
LL sum,res[N];
void dfs(int u,int fa) {
    sz[u]=1;
    for(auto v:g[u]) if(v!=fa) {
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void update(int u,int fa,int val) {
    cnt[w[u]]+=val;
    if(cnt[w[u]]>mx) mx=cnt[w[u]],sum=w[u];
    else if(cnt[w[u]]==mx) sum+=w[u];
    for(auto v:g[u]) if(v!=fa&&v!=sn) {
        update(v,u,val);
    }
}
void dsu(int u,int fa,bool op) {
    for(auto v:g[u]) if(v!=fa&&v!=son[u]) {
        dsu(v,u,true);
    }
    if(son[u]) dsu(son[u],u,false),sn=son[u];
    update(u,fa,1);
    res[u]=sum;
    sn=0;
    if(op) update(u,fa,-1),mx=0,sum=0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    dsu(1,0,true);
    for(int i=1;i<=n;i++) cout<<res[i]<<" \n"[i==n];
    return 0;
}