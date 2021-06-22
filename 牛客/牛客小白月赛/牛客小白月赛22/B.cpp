#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+5;

int n;
ll w[N];
int to[N*2],nxt[N*2],head[N];
int cnt;
bool st[N];
ll dp[N];
ll res=0xc0c0c0c0c0c0c0c0;

void addedge(int u,int v) {
    cnt++;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dfs(int u) {
    st[u]=true;
    bool f=false;
    dp[u]=w[u];
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(st[v]) continue;
        if(!f) f=true;
        dfs(v);
        res=max(res,dp[u]+dp[v]);
        dp[u]=max(dp[u],dp[v]+w[u]);
    }
    res=max(res,dp[u]);
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    memset(dp,0xc0,sizeof dp);
    dfs(1);
    cout<<res<<endl;
    return 0;
}