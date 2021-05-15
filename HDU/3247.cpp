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
const int N=6e4+5;
int n,m,tr[N][2],fail[N],bit[N],cnt,d[11][11],dist[N],dp[11][1024];
bool st[N],vis[11][1024];
VI node;
struct R {
    int d,u,b;
    R() {}
    R(int d,int u,int b):d(d),u(u),b(b) {}
    bool operator < (const R &T) const {
        return d>T.d;
    }
};
void init() {
    for(int i=0;i<=cnt;i++) {
        tr[i][0]=tr[i][1]=fail[i]=bit[i]=0;
        st[i]=false;
    }
    node.clear();
    cnt=0;
}
void insert(const string &s,int x) {
    int u=0;
    for(auto c:s) {
        int v=c-'0';
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
    }
    if(x!=-1) bit[u]|=1<<x;
    else st[u]=true;
}
void build() {
    queue<int> q;
    for(int i=0;i<2;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<2;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
        bit[u]|=bit[fail[u]];
        st[u]|=st[fail[u]];
    }
}
void bfs(int s) {
    queue<int> q;
    for(int i=0;i<=cnt;i++) dist[i]=0x3f3f3f3f;
    q.push(node[s]);
    dist[node[s]]=0;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<2;v++) if(!st[tr[u][v]]&&dist[tr[u][v]]==0x3f3f3f3f) {
            dist[tr[u][v]]=dist[u]+1;
            q.push(tr[u][v]);
        }
    }
    for(int i=0;i<SZ(node);i++) d[s][i]=dist[node[i]];
}
void dijkstra() {
    priority_queue<R> q;
    for(int i=0;i<SZ(node);i++) for(int j=0;j<1<<n;j++) dp[i][j]=0x3f3f3f3f,vis[i][j]=false;
    q.emplace(0,0,0);
    dp[0][0]=0;
    while(SZ(q)) {
        auto x=q.top();
        int u=x.u,b=x.b;
        q.pop();
        if(b==(1<<n)-1) {cout<<x.d<<'\n';return;}
        if(vis[u][b]) continue;
        vis[u][b]=true;
        for(int v=0;v<SZ(node);v++) {
            int tb=b|bit[node[v]];
            if(!vis[v][tb]&&dp[v][tb]>dp[u][b]+d[u][v]) {
                dp[v][tb]=dp[u][b]+d[u][v];
                q.emplace(dp[v][tb],v,tb);
            }
        }
    }
}
void solve() {
    build();
    node.PB(0);
    for(int i=0;i<=cnt;i++) if(bit[i]&&!st[i]) node.PB(i);
    for(int i=0;i<SZ(node);i++) bfs(i);
    dijkstra();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m) {
        if(!n&&!m) break;
        init();
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            insert(s,i);
        }
        for(int i=1;i<=m;i++) {
            string s;
            cin>>s;
            insert(s,-1);
        }
        solve();
    }
    return 0;
}