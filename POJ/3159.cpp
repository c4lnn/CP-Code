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
const int N=30005;
int n,m,dist[N],cnt,to[N*5],val[N*5],nxt[N*5],head[N];
bool st[N];
void addedge(int u,int v,int w) {
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
int dijkstra() {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f;
    priority_queue<PII,VPII,greater<PII> > q;
    q.push(MP(0,1));
    dist[1]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i],w=val[i];
            if(!st[v]&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                q.push(MP(dist[v],v));
            }
        }
    }
    return dist[n];
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    printf("%d\n",dijkstra());
    return 0;
}