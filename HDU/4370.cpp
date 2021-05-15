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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=305;
int n,t,w[N][N],dist[N];
bool st[N];
void dijkstra(int s) {
    for(int i=1;i<=n;i++) st[i]=false,dist[i]=0x3f3f3f3f;
    priority_queue<PII,VPII,greater<PII>> q;
    q.emplace(0,s);
    dist[s]=0;
    t=0x3f3f3f3f;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int v=1;v<=n;v++) {
            if(!st[v]&&dist[v]>dist[u]+w[u][v]) {
                dist[v]=dist[u]+w[u][v];
                q.emplace(dist[v],v);
                if(dist[v]+w[v][s]<t) t=dist[v]+w[v][s];
            }
        }
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&w[i][j]);
        dijkstra(1);
        int res1=dist[n],res2=t;
        dijkstra(n);
        res2+=t;
        printf("%d\n",min(res1,res2));
    }
    return 0;
}