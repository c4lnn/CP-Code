#include<bits/stdc++.h>

using namespace std;

const int N=4e4+5;

int n,m;
int cnt,to[N*2],val[N*2],nxt[N*2],head[N];
int st[N];
int dist[N];
int fa[N];
vector<pair<int,int> >query[N];
int ans[205];

int init() {
    cnt=0;
    memset(head,0,sizeof head);
    memset(st,0,sizeof st);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) query[i].clear();
}
void addedge(int u,int v,int w) {
    cnt++;
    to[cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void addquery(int a,int b,int id) {
    query[a].push_back(make_pair(b,id));
    query[b].push_back(make_pair(a,id));
}
int get(int x) {
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]); 
}
void tarjan(int u) {
    st[u]=1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i],w=val[i];
        if(st[v]) continue;
        dist[v]=dist[u]+w;
        tarjan(v);
        fa[v]=u;
    }
    for(int i=0;i<query[u].size();i++) {
        int v=query[u][i].first,id=query[u][i].second;
        if(st[v]==2) {
            int lca=get(v);
            ans[id]=dist[u]+dist[v]-2*dist[lca];
        }
    }
    st[u]=2;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>n>>m;
        init();
        for(int i=1;i<n;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        for(int i=1;i<=m;i++) {
            int a,b;
            cin>>a>>b;
            addquery(a,b,i);
            addquery(b,a,i);
        }
        tarjan(1);
        for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    } 
     return 0;
}