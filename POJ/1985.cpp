#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N=1e5+5;

int n,m;
int cnt,to[N*2],val[N*2],nxt[N*2],head[N];
int st[N];
int dist[N];
pair<int,int>mx;
void addedge(int u,int v,int w) {
    cnt++;
    to[cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void bfs(int u) {
    queue<int>q;
    mx.first=0;
    memset(st,false,sizeof st);
    q.push(u);
    dist[u]=0;
    st[u]=true;
    while(q.size()) {
        u=q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i],w=val[i];
            if(st[v]) continue;
            st[v]=true;
            dist[v]=dist[u]+w;
            if(dist[v]>mx.first) mx=make_pair(dist[v],v);
            q.push(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        char c;
        cin>>u>>v>>w>>c;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    bfs(1);
    bfs(mx.second);
    cout<<mx.first<<endl;
     return 0;
}