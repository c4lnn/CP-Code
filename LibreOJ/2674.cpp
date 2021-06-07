#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=33000;
const int INF=0x3f3f3f3f;
int n,m,s,t,cur[N],cnt,dist[N],cost,tt[50][200],p[1000];
bool st[N];
struct E {
    int v;
    int c,w;
    int a,b;
    E(){}
    E(int v,int c,int w,int a,int b):v(v),c(c),w(w),a(a),b(b){}
};
vector<E> e;
vi G[N];
vector<pii> ud;
void init() {
    e.clear();
    for(int i=1;i<=n;i++) G[i].clear();
}
void addedge(int u,int v,int c,int w,int a,int b) {
    e.push_back(E(v,c,w,a,b));
    e.push_back(E(u,0,-w,a,b));
    G[u].push_back(e.size()-2);
    G[v].push_back(e.size()-1);
}
bool spfa() {
    for(int i=1;i<=n;i++) dist[i]=INF,st[i]=false;
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(auto x:G[u]) {
            int &v=e[x].v,&c=e[x].c,&w=e[x].w;
            if(c>0&&dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                if(!st[v]) q.push(v),st[v]=true;
            }
        }
    }
    return dist[t]!=INF;
}
int dfs(int u,int a) {
    if(u==t) return a;
    int f,flow=0;
    st[u]=true;
    for(int &i=cur[u];i<G[u].size();i++) {
        int &v=e[G[u][i]].v,&c=e[G[u][i]].c,&w=e[G[u][i]].w;
        if(st[v]||c<=0||dist[v]!=dist[u]+w||(f=dfs(v,min(a,c)))<=0) continue;
        if(v==t) ud.push_back(mp(e[G[u][i]].a,e[G[u][i]].b));
        c-=f;
        e[G[u][i]^1].c+=f;
        a-=f;
        flow+=f;
        cost+=f*w;
        if(a==0) break;
    }
    st[u]=false;
    return flow;
}
void dinic(int x) {
    n=t+cnt;
    while(spfa()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        dfs(s,INF);
        for(int j=0;j<ud.size();j++) {
            n++;
            addedge(n,t,1,0,ud[j].fi,ud[j].se+1);
            for(int i=1;i<=x;i++) addedge(i,n,1,(ud[j].se+1)*tt[i][ud[j].fi],0,0);
        }
        ud.clear();
    }
    printf("%d\n",cost);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&tt[i][j]);
    s=n+1,t=n+2;
    for(int i=1;i<=n;i++) addedge(s,i,p[i],0,0,0);
    for(int i=1;i<=m;i++) {
        int x=t+(++cnt);
        addedge(x,t,1,0,i,1);
        for(int j=1;j<=n;j++) addedge(j,x,1,tt[j][i],0,0);
    }
    dinic(n);
    return 0;
}