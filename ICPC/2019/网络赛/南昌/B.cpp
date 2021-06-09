#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int N=1e3+5;
const int M=5e5+5;
int v,e,s,k,c,cnt,to[M],val[M],nxt[M],head[N],dis[N],vis[N],xfy[N],o;
void init1() {
    cnt=0;
    for(int i=1;i<=k+k+e+e;i++) to[i]=val[i]=0;
    for(int i=0;i<=v;i++) head[i]=0;
}
void init2() {
    for(int i=0;i<=v;i++) vis[i]=0,dis[i]=INF;
    dis[o]=0;
}
void addEdge(int a,int b,int d) {
    cnt++;
    to[cnt]=b;
    val[cnt]=d;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void dijkstra() {
	priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push(pii(0,o));
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int e=head[u];e;e=nxt[e])
            if(dis[u]<INF&&dis[to[e]]>dis[u]+val[e]) {
                dis[to[e]]=dis[u]+val[e];
                q.push(pii(dis[to[e]],to[e]));
            }
    }
}
int main() {
    int T;
    scanf("%d",&T);
    int a,b,d,resXfy,resHero;
    while(T--) {
        scanf("%d%d%d%d%d",&v,&e,&s,&k,&c);
        init1();
        resXfy=-1;
        resHero=-1;
        for(int i=0;i<k;i++) scanf("%d",&xfy[i]);
        while(e--) {
            scanf("%d%d%d",&a,&b,&d);
            addEdge(a,b,d);
            addEdge(b,a,d);
        }
        o=s;
        init2();
        dijkstra();
        for(int i=1;i<=v;i++) resHero=max(resHero,dis[i]);
        for(int i=0;i<k;i++) addEdge(0,xfy[i],0),addEdge(xfy[i],0,0);
        o=0;
        init2();
        dijkstra();
        for(int i=1;i<=v;i++) resXfy=max(resXfy,dis[i]);
        if(resHero<=resXfy*c) printf("%d\n",resHero);
        else printf("%d\n",resXfy);
    }
    return 0;
}