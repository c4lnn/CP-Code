#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,k;
int u[N],v[N];
int path[N];
int cnt,to[N],nxt[N],head[N];
int d[N];
void addedge(int u,int v) {
    cnt++;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void bfs() {
    queue<int>q;
    q.push(path[k]);
    d[path[k]]=1;
    while(q.size()) {
        auto u=q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i];
            if(d[v]) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
}
void solve() {
    cnt=0;
    memset(head,0,sizeof head);
    for(int i=1;i<=m;i++) addedge(u[i],v[i]);
    int mn=0,mx=0;
    for(int i=1;i<k;i++) {
        if(d[path[i+1]]>=d[path[i]]) mx++,mn++;
        else for(int j=head[path[i]];j;j=nxt[j]) {
            int x=to[j];
            if(d[x]==d[path[i]]-1&&x!=path[i+1]){mx++;break;}
        }
    }
    cout<<mn<<" "<<mx<<endl;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>u[i]>>v[i];
        addedge(v[i],u[i]);
    }
    cin>>k;
    for(int i=1;i<=k;i++) cin>>path[i];
    bfs();
    solve();
    return 0;
}