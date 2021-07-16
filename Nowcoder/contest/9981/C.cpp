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
//head
const int N=1e5+5;
int n,w[N],c[N];
VI g[N];
bool dfs(int u,int fa) {
    int t=0;
    for(auto v:g[u]) {
        if(v==fa) continue;
        if(!dfs(v,u)) return false;
        t+=w[v];
    }
    if(t>1||u==1&&!t) return false;
    if(!t) w[u]=1;
    return true;
}
void color(int u,int fa) {
    c[u]=w[u]?c[fa]:c[fa]^1;
    for(auto v:g[u]) {
        if(v==fa) continue;
        color(v,u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    if(!dfs(1,0)) return cout<<-1<<'\n',0;
    color(1,0);
    for(int i=1;i<=n;i++)  cout<<(c[i]?'R':'B');
    cout<<'\n';
    return 0;
}