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
const int N=405;
int cnt,vis[N];
DB x[N],y[N],w[N][N],dist[N];
bool st[N];
DB calc(int a,int b,bool f) {
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]))*3/(f?2000:500);
}
DB dijkstra() {
    priority_queue<pair<DB,int>,vector<pair<DB,int> >,greater<pair<DB,int> > > q;
    q.push(MP(0,1));
    for(int i=1;i<=cnt;i++) dist[i]=0x3f3f3f3f;
    dist[1]=0;
    while(SZ(q)) {
        int u=q.top().SE;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(int v=1;v<=cnt;v++) {
            if(!st[v]&&dist[v]>dist[u]+w[u][v]) {
                dist[v]=dist[u]+w[u][v];
                q.push(MP(dist[v],v));
            }
        }
    }
    return dist[2];
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    for(int i=1;i<=2;i++) scanf("%lf%lf",&x[i],&y[i]);
    cnt=2;
    int t=1;
    DB a,b;
    while(~scanf("%lf%lf",&a,&b)) {
        if(a==-1&&b==-1) {++t;continue;}
        vis[++cnt]=t;
        x[cnt]=a,y[cnt]=b;
    }
    for(int i=1;i<=cnt;i++) {
        for(int j=i+1;j<=cnt;j++) {
            if(vis[i]&&vis[i]==vis[j]&&j-i==1) w[i][j]=w[j][i]=calc(i,j,true);
            else w[i][j]=w[j][i]=calc(i,j,false);
        }
    }
    printf("%.0f\n",dijkstra());
    return 0;
}