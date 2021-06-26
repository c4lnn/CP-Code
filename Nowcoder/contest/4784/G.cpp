#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int n;
int cnt,to[N*2],nxt[N*2],head[N];
long long sz[N],tot[N];

void addedge(int a,int b) {
    cnt++;
    to[cnt]=b;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void dfs(int u,int pre) {
    sz[u]=1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(v==pre) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    tot[u]=sz[u]*(n-sz[u]);
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        addedge(a,b);
        addedge(b,a);
    }
    dfs(1,0);
    sort(tot+2,tot+1+n);
    long long ans=0;
    for(int i=2;i<=n;i++) ans+=tot[i]*(n-i+1);
    cout<<ans<<endl;
    return 0;
}