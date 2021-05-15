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
const int N=1e3+5;
VPII g[N];
int n,m;
bool st[N][N];
struct R {
    int u,v,d;
    R() {}
    R(int u,int v,int d):u(u),v(v),d(d) {}
    bool operator < (const R &T) const {
        return d>T.d;
    }
};
int bfs() {
    priority_queue<R> q;
    q.emplace(1,n,0);
    while(SZ(q)) {
        int u=q.top().u,v=q.top().v,d=q.top().d;
        q.pop();
        if(u==v) return d;
        if(st[u][v]) continue;
        st[u][v]=true;
        for(auto x:g[u]) if(x.FI==v) return d+1;
        for(auto x:g[u])
            for(auto y:g[v])
                if(!st[x.FI][y.FI]&&x.SE==y.SE) {
                    if(x.FI==y.FI) return d+2;
                    q.emplace(x.FI,y.FI,d+2);
                }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        char c;
        cin>>u>>v>>c;
        w=c-'a';
        g[u].EB(v,w);
        if(u!=v) g[v].EB(u,w);
    }
    cout<<bfs()<<'\n';
    return 0;
}