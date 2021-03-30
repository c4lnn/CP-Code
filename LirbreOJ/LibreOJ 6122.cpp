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
const int N=205;
const int INF=0x3f3f3f3f;
int n,m,a[N],dist[N],h[N],preu[N],pree[N<<1];
map<string,int> mp;
string s[N];
bool f;
struct E {
    int v;
    int c,w;
    E(){}
    E(int v,int c,int w):v(v),c(c),w(w){}
};
vector<E> e;
VI g[N];
void add_edge(int u,int v,int c,int w) {
    e.EB(v,c,w);
    e.EB(u,0,-w);
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool dijkstra(int n,int s,int t) {
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<PII,VPII,greater<PII>> q;
    dist[s]=0;
    q.emplace(0,s);
    while(SZ(q)) {
        int d=q.top().FI,u=q.top().SE;
        q.pop();
        if(dist[u]!=d) continue;
        for(auto x:g[u]) {
            int v=e[x].v,c=e[x].c,w=e[x].w;
            if(c>0&&dist[v]>dist[u]-h[v]+w+h[u]) {
                dist[v]=dist[u]-h[v]+w+h[u];
                preu[v]=u;
                pree[v]=x;
                q.emplace(dist[v],v);
            }
        }
    }
    return dist[t]!=INF;
}
PII mcmf(int n,int s,int t) {
    int flow=0,cost=0;
    while(dijkstra(n,s,t)) {
        int c=INF;
        for(int i=1;i<=n;i++) h[i]=min(INF,h[i]+dist[i]);
        for(int u=t;u!=s;u=preu[u]) c=min(c,e[pree[u]].c);
        flow+=c;
        cost+=c*h[t];
        for(int u=t;u!=s;u=preu[u]) {
            e[pree[u]].c-=c;
            e[pree[u]^1].c+=c;
        }
    }
    return MP(flow,cost);
}
void dfs(int u,int t) {
    a[t]=u;
    if(u==n) {
        if(!f) {
            f^=1;
            for(int i=1;i<=t;i++) cout<<s[a[i]]<<'\n';
        }
        else for(int i=t-1;i>=1;i--) cout<<s[a[i]]<<'\n';
        return;
    }
    for(auto x:g[u+n]) {
        if(e[x].v!=u&&e[x].c!=INF) dfs(e[x].v,t+1);
        if(e[x].v!=u&&e[x].c==INF-2) dfs(e[x].v,t+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        mp[s[i]]=i;
    }
    for(int i=1;i<=n;i++) add_edge(i,i+n,i==1||i==n?2:1,-1);
    for(int i=1;i<=m;i++) {
        string s1,s2;
        cin>>s1>>s2;
        int u=mp[s1],v=mp[s2];
        if(u>v) swap(u,v);
        add_edge(u+n,v,INF,0);
    }
    PII res=mcmf(n+n,1,n+n);
    if(res.FI!=2) cout<<"No Solution!"<<'\n';
    else {
        cout<<-res.SE-2<<'\n';
        dfs(1,1);
    }
    return 0;
}