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
int n,s,t,dist[N];
bool st[N];
VPII g[N];
int dijkstra() {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f;
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
    return dist[t]==0x3f3f3f3f?-1:dist[t];
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d%d",&n,&s,&t);
    for(int u=1;u<=n;u++) {
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++) {
            int v;
            scanf("%d",&v);
            g[u].PB(MP(v,j==1?0:1));
        }
    }
    printf("%d\n",dijkstra());
    return 0;
}