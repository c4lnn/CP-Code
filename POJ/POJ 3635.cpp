#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int N=1e3+5;

int n,m;
int p[N];
int cnt;
int w[N*20];
int to[N*20];
int nxt[N*20];
int head[N];
int dis[N][N/10];
bool vis[N][N/10];
int c,s,e;

void add(int a,int b,int c) {
    cnt++;
    w[cnt]=c;
    to[cnt]=b;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[s][0]=0;
    priority_queue<piii,vector<piii>,greater<piii> >q;
    q.push(make_pair(0,make_pair(s,0)));
    while(!q.empty()) {
        int x=q.top().second.first;
        int t=q.top().second.second;
        if(x==e) {
            cout<<dis[x][t]<<endl;
            return;
        }
        q.pop();
        if(vis[x][t]==true) continue;
        vis[x][t]=true;
        if(t<c&&dis[x][t+1]>dis[x][t]+p[x]) dis[x][t+1]=dis[x][t]+p[x],q.push(make_pair(dis[x][t]+p[x],make_pair(x,t+1)));
        for(int i=head[x];i;i=nxt[i]) {
            int y=to[i];
            if(t>=w[i]&&dis[y][t-w[i]]>dis[x][t]) dis[y][t-w[i]]=dis[x][t],q.push(make_pair(dis[y][t-w[i]],make_pair(y,t-w[i])));
        }
    }
    cout<<"impossible"<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=1;i<=m;i++) {
        int u,v,d;
        cin>>u>>v>>d;
        add(u,v,d);
        add(v,u,d);
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        cin>>c>>s>>e;
        dijkstra();
    }
    return 0;
}