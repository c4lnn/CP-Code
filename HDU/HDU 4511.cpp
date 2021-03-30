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
const int N=51;
int n,m,tr[N*10][N],fail[N*10],sz;
bool st[N*10],vis[N][N*10];
DB x[N],y[N],d[N][N],dist[N][N*10];
struct R {
    DB w;
    int u,node;
    R() {}
    R(DB w,int u,int node):w(w),u(u),node(node) {}
    bool operator < (const R &T) const {
        return w>T.w;
    }
};
DB calc(DB x1,DB y1,DB x2,DB y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void init() {
    for(int i=0;i<=sz;i++) {
        for(int j=0;j<=n;j++) tr[i][j]=0;
        fail[i]=0;
        st[i]=false;
    }
    sz=0;
}
void insert() {
    int u=0,k;
    cin>>k;
    for(int i=1;i<=k;i++) {
        int v;
        cin>>v;
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
    }
    st[u]=true;
}
void build() {
    queue<int> q;
    for(int i=1;i<=n;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=1;v<=n;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
        st[u]|=st[fail[u]];
    }
}
void dijkstra() {
    build();
    for(int i=0;i<=n;i++) for(int j=0;j<=sz;j++) dist[i][j]=1e18,vis[i][j]=false;
    priority_queue<R> q;
    q.emplace(0,tr[0][1],1);
    dist[1][tr[0][1]]=0;
    while(SZ(q)) {
        int u=q.top().u,node=q.top().node;
        if(node==n) {cout<<fixed<<setprecision(2)<<q.top().w<<'\n';return;}
        q.pop();
        if(vis[node][u]) continue;
        vis[node][u]=true;
        for(int v=node+1;v<=n;v++) if(!vis[v][tr[u][v]]&&!st[tr[u][v]]&&dist[v][tr[u][v]]>dist[node][u]+d[node][v]) {
            dist[v][tr[u][v]]=dist[node][u]+d[node][v];
            q.emplace(dist[v][tr[u][v]],tr[u][v],v);
        }
    }
    cout<<"Can not be reached!"<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m) {
        if(!n&&!m) break;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) d[i][j]=calc(x[i],y[i],x[j],y[j]);
        for(int i=1;i<=m;i++) insert();
        dijkstra();
        init();
    }
    return 0;
}