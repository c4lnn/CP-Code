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
int n,t,cnt;
bool st[N];
void dfs(int u) {
    st[u]=true;
    for(auto v:g[u]) if(!st[v]) {
        while(t<v) ++cnt,dfs(t++);
        if(t>v) continue;
        dfs(t++);
    }
    if(u==1) while(t!=n+1) ++cnt,dfs(t++);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int m;cin>>n>>m;
        for(int i=1;i<=n;i++) {
            g[i].clear();
            st[i]=false;
        }
        for(int i=1;i<=m;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v);
            g[v].PB(u);
        }
        t=2,cnt=0;
        for(int i=1;i<=n;i++) sort(ALL(g[i]));
        dfs(1);
        cout<<cnt<<'\n';
    }
    return 0;
}