#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int INF=0x3f3f3f3f;
int n,m,s,t,dist[N],cur[N],cost,a[N][N],b[N][N],o,p;
bool st[N];
vector<int> G[N];
struct E {
    int v,c,w;
    E(){}
    E(int v,int c,int w):v(v),c(c),w(w){}
};
struct Q {
    int u,v,s,t,c;
}c[N];
vector<E> e;
void addedge(int u,int v,int c,int w) {
    e.push_back(E(v,c,w));
    e.push_back(E(u,0,-w));
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
int dinic() {
    int flow=0;
    while(spfa()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        flow+=dfs(s,INF);
    }
    return flow;
}
int main() {
    scanf("%d%d%d%d",&n,&m,&o,&p);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
    s=m*2+1,t=m*2+3;
    addedge(s+1,s,o,0);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d%d%d",&c[i].u,&c[i].v,&c[i].s,&c[i].t,&c[i].c);
        c[i].u++,c[i].v++;
        addedge(i*2-1,i*2,1,-c[i].c);
        if(a[1][c[i].u]<=c[i].s) addedge(s,i*2-1,1,b[1][c[i].u]);
        if(a[c[i].v][1]+c[i].t<=p) addedge(i*2,t,1,b[c[i].v][1]);
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) {
            if(i==j) continue;
            if(c[i].t+a[c[i].v][c[j].u]<=c[j].s) addedge(i*2,j*2-1,1,b[c[i].v][c[j].u]);
        }
    s++;
    n=t;
    dinic();
    printf("%d\n",-cost);
    return 0;
}