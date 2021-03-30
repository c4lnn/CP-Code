#include <bits/stdc++.h>
#define int long long
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
const int MOD=1e9+7;
int n,sz[N],fac[N],res;
VPII g[N];
void dfs(int u,int fa) {
    sz[u]=1;
    for(auto x:g[u]) {
        int v=x.FI,w=x.SE;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        res=(res+sz[v]*(n-sz[v])%MOD*w%MOD)%MOD;
    }
}
signed main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    fac[0]=1;
    for(int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%MOD;
    while(~scanf("%lld",&n)) {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++) {
            int u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            g[u].EB(v,w);
            g[v].EB(u,w);
        }
        res=0;
        dfs(1,0);
        printf("%lld\n",res*fac[n-1]%MOD*2%MOD);
    }
    return 0;
}