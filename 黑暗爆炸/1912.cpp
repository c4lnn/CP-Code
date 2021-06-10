#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k;
int cnt,to[N*2],val[N*2],nxt[N*2],head[N];
int dp[N],path[3][N],res,root;
bool st[N];
void addedge(int u,int v) {
    cnt++;
    to[cnt]=v;
    val[cnt]=1;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dfs(int u) {
    st[u]=true;
    int mx1=0,mx2=0;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i],w=val[i];
        if(st[v]) continue;;
        dfs(v);
        if(dp[v]+w>dp[u]) mx2=dp[u],mx1=dp[u]=dp[v]+w,path[2][u]=path[1][u],path[1][u]=i;
        else if(dp[v]+w>mx2) mx2=dp[v]+w,path[2][u]=i;
    }
    if(mx1+mx2>res) res=mx1+mx2,root=u;
}
void update() {
    for(int i=path[1][root];i;i=path[1][to[i]]) val[i]=val[i^1]=-1;
    for(int i=path[2][root];i;i=path[1][to[i]]) val[i]=val[i^1]=-1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1);
    int ans=2*(n-1)-res+1;
    if(k==2){
        update();
        res=0;memset(dp,0,sizeof dp);memset(st,false,sizeof st);memset(path,0,sizeof path);
        dfs(1);
        ans=ans-res+1;
    }
    cout<<ans<<endl;
    return 0;
}