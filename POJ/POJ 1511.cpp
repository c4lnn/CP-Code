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
const int N=1000005;
int n,m,u[N],v[N],w[N],to[N],val[N],nxt[N],head[N],cnt;
LL dist[N];
bool st[N];
void addedge(int u,int v,int w) {
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dijkstra() {
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f3f3f3f3f,st[i]=false;
    priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > q;
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
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
        cnt=0;
        for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<=m;i++) addedge(u[i],v[i],w[i]);
        dijkstra();
        LL res=0;
        for(int i=1;i<=n;i++) res+=dist[i];
        cnt=0;
        for(int i=1;i<=n;i++) head[i]=0;
        for(int i=1;i<=m;i++) addedge(v[i],u[i],w[i]);
        dijkstra();
        for(int i=1;i<=n;i++) res+=dist[i];
        printf("%lld\n",res);
    }
    return 0;
}