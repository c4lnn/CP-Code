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
int n,m,s,dist1[N],dist2[N];
VPII g1[N],g2[N];
bool st[N];
void dijkstra(VPII *g,int *dist) {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f,st[i]=false;
    priority_queue<PII,VPII,greater<PII> > q;
    q.push(MP(0,s));
    dist[s]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i].FI,w=g[u][i].SE;
            if(!st[v]&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                q.push(MP(dist[v],v));
            }
        }
    }
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g1[u].PB(MP(v,w));
        g2[v].PB(MP(u,w));
    }
    dijkstra(g1,dist1);
    dijkstra(g2,dist2);
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dist1[i]+dist2[i]);
    printf("%d\n",res);
    return 0;
}