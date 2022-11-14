#include<iostream>
#include<cstring>

using namespace std;

const int N=2e5+5;
const int M=4e5+5;

int n;
int cnt;
int to[M],val[M],nxt[M],head[N],deg[N];
bool st[N];
int dp[N];
int f[N];

void init() {
    cnt=0;
    memset(head,0,sizeof head);
    memset(deg,0,sizeof deg);
    memset(st,false,sizeof st);
    memset(dp,0,sizeof dp);
}
void addedge(int u,int v,int w) {
    ++cnt;
    to[cnt]=v;
    val[cnt]=w;
    nxt[cnt]=head[u];
    head[u]=cnt;
    deg[u]++;
}
void dfs1(int u) {
    st[u]=true;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i],w=val[i];
        if(st[v]) continue;
        dfs1(v);
        if(deg[v]==1) dp[u]+=w;
        else dp[u]+=min(dp[v],w);
    }
}
void dfs2(int u) {
    st[u]=true;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i],w=val[i];
        if(st[v]) continue;
        if(deg[u]==1) f[v]=dp[v]+w;
        else if(deg[v]==1) f[v]=min(w,f[u]-w);
        else f[v]=dp[v]+min(w,f[u]-min(w,dp[v]));
        dfs2(v);
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        init();
        cin>>n;
        for(int i=1;i<n;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        dfs1(1);
        memset(st,false,sizeof st);
        f[1]=dp[1];
        dfs2(1);
        int res=0;
        for(int i=1;i<=n;i++) res=max(res,f[i]);
        cout<<res<<endl;
    }
     return 0;
}