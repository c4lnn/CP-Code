#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
//head
const int N=1e5+5;
int n,m;
vector<pii>g[2][N];
ll dist[2][N];
bool st[N];
struct node {
    int u,v,w;
}edge[N*2];
void dijkstra(int s,int t) {
    memset(dist[t],0x3f,sizeof dist[t]);
    if(t) memset(st,false,sizeof st);
    dist[t][s]=0;
    priority_queue<pli,vector<pli>,greater<pli>>q;
    q.push({0,s});
    while(q.size()) {
        int u=q.top().se;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[t][u]) {
            int v=x.fi,w=x.se;
            if(st[v]) continue;
            if(dist[t][u]+w<dist[t][v]) {
                dist[t][v]=dist[t][u]+w;
                q.push({dist[t][v],v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
        g[0][u].pb({v,w});
        g[1][v].pb({u,w});
    }
    dijkstra(1,0);
    dijkstra(n,1);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        int x;
        cin>>x;
        int u=edge[x].u,v=edge[x].v,w=edge[x].w;
        if(dist[0][v]+w+dist[1][u]<dist[0][n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}