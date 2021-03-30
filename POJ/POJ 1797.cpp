#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1005;
int n,m,dist[N];
bool st[N];
VPII g[N];
int dijkstra() {
    for(int i=1;i<=n;i++) st[i]=false,dist[i]=0;
    priority_queue<PII> q;
    q.push(MP(0,1));
    dist[1]=0x3f3f3f3f;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i].FI,w=g[u][i].SE;
            if(!st[v]&&dist[v]<min(dist[u],w)) {
                dist[v]=min(dist[u],w);
                q.push(MP(dist[v],v));
            }
        }
    }
    return dist[n];
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u].PB(MP(v,w));
            g[v].PB(MP(u,w));
        }
        printf("Scenario #%d:\n%d\n\n",cs,dijkstra());
    }
    return 0;
}