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
const int N=105;
int n,m,dist[N],p[N],l[N];
bool st[N];
VPII g[N];
int dijkstra(int t) {
    priority_queue<PII,VPII,greater<PII> > q;
    q.push(MP(0,n+1));
    for(int i=1;i<=n+1;i++) dist[i]=0x3f3f3f3f,st[i]=false;
    dist[n+1]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i].FI,w=g[u][i].SE;
            if(l[v]<t||l[v]-t>m) st[v]=true;
            if(!st[v]&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                q.push(MP(dist[v],v));
            }
        }
    }
    return dist[1];
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d",&m,&n);
    int x;
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d",&p[i],&l[i],&x);
        for(int j=1;j<=x;j++) {
            int t,v;
            scanf("%d%d",&t,&v);
            g[t].PB(MP(i,v));
        }
    }
    for(int i=1;i<=n;i++) g[n+1].PB(MP(i,p[i]));
    int res=0x3f3f3f3f;
    for(int i=l[1]-m;i<=l[1];i++) res=min(res,dijkstra(i));
    printf("%d\n",res);
    return 0;
}