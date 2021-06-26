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
int n,a[N],dist[N][105];
bool st[N];
VI g[N];
void bfs() {
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=100;i++) {
        memset(st,false,sizeof st);
        queue<int> q;
        for(int j=1;j<=n;j++) if(a[j]<=i) {
            q.push(j);
            st[j]=true;
            dist[j][i]=0;
        }
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            for(auto v:g[u]) if(!st[v]) {
                st[v]=true;
                dist[v][i]=dist[u][i]+1;
                q.push(v);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v),g[v].PB(u);
    }
    bfs();
    for(int i=1;i<=q;i++) {
        int u,w;cin>>u>>w;
        cout<<(dist[u][w]==0x3f3f3f3f?-1:dist[u][w])<<'\n';
    }
    return 0;
}