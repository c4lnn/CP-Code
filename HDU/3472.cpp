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
const int N=30;
const int INF=0x3f3f3f3f;
int fa[N],deg[N],d[N],cur[N],sz[N];
bool vis[N];
VI g[N];
VPII e;
void init(int n) {
    for(int i=1;i<=n;i++) g[i].clear();
    e.clear();
}
void add_edge(int u,int v,int c) {
    e.EB(v,c);
    e.EB(u,0);
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool bfs(int n,int s,int t) {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    q.push(s);
    d[s]=1;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto x:g[u]) {
            int v=e[x].FI,c=e[x].SE;
            if(d[v]||c<=0) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    return d[t];
}
int dfs(int u,int a,int t) { // 多路增广
    if(u==t) return a;
    int f,flow=0;
    for(int &i=cur[u];i<SZ(g[u]);i++) {
        int v=e[g[u][i]].FI,&c=e[g[u][i]].SE;
        if(d[v]!=d[u]+1||c<=0||(f=dfs(v,min(a,c),t))<=0) continue;
        c-=f;
        e[g[u][i]^1].SE+=f;
        a-=f;
        flow+=f;
        if(a==0) break;
    }
    return flow;
}
int dinic(int n,int s,int t) {
    int flow=0;
    while(bfs(n,s,t)) {
        for(int i=1;i<=n;i++) cur[i]=0;
        flow+=dfs(s,INF,t);
    }
    return flow;
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    fa[fx]=fy;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    int s=27,t=28;
    for(int cs=1;cs<=T;cs++) {
        init(t);
        int n;cin>>n;
        for(int i=1;i<=26;i++) deg[i]=0,vis[i]=false,fa[i]=i;
        for(int i=1;i<=n;i++) {
            string s;int f;cin>>s>>f;
            int st=s[0]-'a'+1,ed=s[SZ(s)-1]-'a'+1;
            if(f) add_edge(st,ed,1);
            --deg[st],++deg[ed];
            vis[st]=vis[ed]=true;
            merge(st,ed);
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=26;i++) if(vis[i]&&fa[i]==i) ++cnt1;
        for(int i=1;i<=26;i++) if(deg[i]&1) ++cnt2;
        if(cnt1==1&&(cnt2==0||cnt2==2)) {
            if(cnt2==2) {
                int a=-1,b=-1;
                for(int i=1;i<=26;i++) if(deg[i]&1) {
                    if(a==-1) a=i;
                    else b=i;
                }
                --deg[a],++deg[b];
                add_edge(a,b,1);
            }
            int sum=0;
            for(int i=1;i<=26;i++) {
                if(deg[i]<0) add_edge(s,i,-deg[i]/2),sum-=deg[i]/2;
                else if(deg[i]>0) add_edge(i,t,deg[i]/2);
            }
            cout<<"Case "<<cs<<": "<<(dinic(t,s,t)==sum?"Well done!":"Poor boy!")<<'\n';
        }
        else cout<<"Case "<<cs<<": Poor boy!\n";
    }
    return 0;
}