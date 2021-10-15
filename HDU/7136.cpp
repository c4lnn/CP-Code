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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=1e5+5;
int fa[N],dep[N];
PII a[N];
VI g[N],gg[N];
bool st[N];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void dfs(int u,int fa) {
    for(auto v:gg[u]) if(v!=fa) {
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            g[i].clear();
            gg[i].clear();
            st[i]=false;
            fa[i]=i;
        }
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v);
            g[v].PB(u);
        }
        for(int i=1;i<=n;i++) {
            cin>>a[i].FI;
            a[i].SE=i;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) {
            int u=a[i].SE;
            for(auto v:g[u]) if(st[v]) {
                int fv=find(v);
                gg[u].PB(fv);
                fa[fv]=u;
            }
            st[u]=true;
        }
        dep[a[n].SE]=1;
        dfs(a[n].SE,0);
        for(int i=1;i<=n;i++) cout<<dep[i]<<'\n';
    }
    return 0;
}