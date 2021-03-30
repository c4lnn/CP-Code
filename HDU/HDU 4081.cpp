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
const int N=1005;
DB x[N],y[N],dist[N][N],mx[N][N];
int n,p[N],fa[N];
bool vis[N][N];
DB prim() {
    for(int i=1;i<=n;i++) {
        fa[i]=-1;
        for(int j=1;j<=n;j++) mx[i][j]=0,vis[i][j]=false;
    }
    priority_queue<pair<DB,PII>,vector<pair<DB,PII>>,greater<pair<DB,PII>>> q;
    DB mst=0;
    q.emplace(0,MP(1,0));
    while(SZ(q)) {
        int u=q.top().SE.FI,f=q.top().SE.SE;
        DB w=q.top().FI;
        q.pop();
        if(fa[u]!=-1) continue;
        fa[u]=f;
        vis[u][fa[u]]=vis[fa[u]][u]=true;
        mx[fa[u]][u]=mx[u][fa[u]]=w;
        mst+=w;
        for(int v=1;v<=n;v++) {
            if(v==u) continue;
            if(fa[v]!=-1) mx[u][v]=mx[v][u]=max(mx[u][fa[u]],mx[fa[u]][v]);
            else q.emplace(dist[u][v],MP(v,u));
        }
    }
    return mst;
}
DB solve() {
    DB mst=prim(),res=0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(vis[i][j]) res=max(res,(p[i]+p[j])/(mst-dist[i][j]));
            else res=max(res,(p[i]+p[j])/(mst-mx[i][j]));
        }
    }
    return res;
}
DB calc(DB ax,DB ay,DB bx,DB by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>p[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                dist[i][j]=dist[j][i]=calc(x[i],y[i],x[j],y[j]);
        cout<<fixed<<setprecision(2)<<solve()<<'\n';
    }
    return 0;
}