#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
int dist[N];
VPII g[N];
void dfs(int u,int fa) {
    for(int i=0;i<SZ(g[u]);i++) if(g[u][i].FI!=fa) {
        dist[g[u][i].FI]=dist[u]+g[u][i].SE;
        dfs(g[u][i].FI,u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<n;i++) {
        int u,v,w;cin>>u>>v>>w;
        g[u].PB(MP(v,w));
        g[v].PB(MP(u,w));
    }
    int mx=0;
    dfs(1,0);
    for(int i=1;i<=n;i++) if(dist[i]>dist[mx]) mx=i;
    for(int i=1;i<=n;i++) dist[i]=0;
    dfs(mx,0);
    for(int i=1;i<=n;i++) if(dist[i]>dist[mx]) mx=i;
    cout<<dist[mx]*11+dist[mx]*(dist[mx]-1)/2<<'\n';
    return 0;
}