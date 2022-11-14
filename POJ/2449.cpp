#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int,int>pii;
typedef pair<int,pii>piii;
const int N=1e5+5;

int n,m;
int cnt;
int a[N],b[N],c[N];
int to[N],val[N],nxt[N],head[N];
int st[N];
int f[N];
int s,t,k;

void addedge(int a,int b,int c) {
    cnt++;
    to[cnt]=b;
    val[cnt]=c;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void dijkstra() {
    memset(f,0x3f,sizeof f);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    f[t]=0;
    q.push(make_pair(0,t));
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        if(st[u]) continue;
        st[u]=1;
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i];
            if(f[v]>f[u]+val[i]) {
                f[v]=f[u]+val[i];
                q.push(make_pair(f[v],v));
            }
        }
    }
}
int astar() {
    memset(st,0,sizeof st);
    priority_queue<piii,vector<piii>,greater<piii> >q;
    q.push(make_pair(f[s],make_pair(0,s)));
    while(!q.empty()) {
        int u=q.top().second.second;
        int w=q.top().second.first;
        q.pop();
        if(st[u]>k) continue;
        st[u]++;
        if(st[u]==k&&u==t) return w;
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i];
            q.push(make_pair(w+val[i]+f[v],make_pair(w+val[i],v)));
        }
    }
    return -1;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
    cin>>s>>t>>k;
    if(s==t) k++;
     for(int i=1;i<=m;i++) addedge(b[i],a[i],c[i]);
     dijkstra();
    cnt=0;
     memset(head,0,sizeof head);
     for(int i=1;i<=m;i++) addedge(a[i],b[i],c[i]);
    cout<<astar()<<endl;
    return 0;
}