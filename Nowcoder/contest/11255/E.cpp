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
int w[N],l[N],r[N];
VPII g[N],o;
void solve(int u,int r,int x) {
    if(r<0) return;
    int l=0;
    for(int i=29;~i;i--) if(r>=1<<i) {
        int d=((w[u]>>i)^(l>>i))<<i;
        o.EB(d,x);
        o.EB(d+(1<<i),-x);
        l+=1<<i;
        r-=1<<i;
    }
    o.EB(l^w[u],x);
    o.EB((l^w[u])+1,-x);
}
void dfs(int u,int fa) {
    solve(u,l[u]-1,-1);
    solve(u,r[u],1);
    for(auto x:g[u]) {
        int v=x.FI;
        if(v==fa) continue;
        w[v]=w[u]^x.SE;
        dfs(v,u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for(int i=1;i<n;i++) {
        int u,v,w;cin>>u>>v>>w;
        g[u].EB(v,w);
        g[v].EB(u,w);
    }
    dfs(1,0);
    sort(ALL(o));
    int res=0,len=0,pre=o[0].FI;
    for(auto x:o) {
        if(x.FI!=pre&&len==n) res+=x.FI-pre;
        len+=x.SE;
        pre=x.FI;
    }
    cout<<res<<'\n';
    return 0;
}