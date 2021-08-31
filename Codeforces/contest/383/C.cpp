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
const int N=2e5+5;
int n,dfn[N],sz[N],f[N],w[N],a[N],b[N],cnt;
VI g[N];
void update(int *a,int x,int v) {
    for(int i=x;i<=n;i+=i&-i) a[i]+=v;
}
int query(int *a,int x) {
    int ret=0;
    for(int i=x;i;i-=i&-i) ret+=a[i];
    return ret;
}
void dfs(int u,int fa) {
    sz[u]=1;
    f[u]=f[fa]^1;
    dfn[u]=++cnt;
    for(auto v:g[u]) if(v!=fa) {
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++) {
        int o;cin>>o;
        if(o==1) {
            int x,v;cin>>x>>v;
            update(f[x]?a:b,dfn[x],v);
            update(f[x]?a:b,dfn[x]+sz[x],-v);
        }
        else {
            int x;cin>>x;
            cout<<query(f[x]?a:b,dfn[x])-query(f[x]?b:a,dfn[x])+w[x]<<'\n';
        }
    }
    return 0;
}