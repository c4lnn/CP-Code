#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=1e5+5;
vi g[N];
int w[N],sz[N],son[N],cnt[N],mx,sn;
ll sum,ans[N];
void dfs1(int u,int fa) {
    sz[u]=1;
    for(auto v:g[u]) {
        if(v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void update(int u,int fa,int val) {
    cnt[w[u]]+=val;
    if(cnt[w[u]]>mx) mx=cnt[w[u]],sum=w[u];
    else if(cnt[w[u]]==mx) sum+=w[u];
    for(auto v:g[u]) {
        if(v==fa||v==sn) continue;
        update(v,u,val);
    }
}
void dfs2(int u,int fa,bool op) {
    for(auto v:g[u]) {
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,true);
    }
    if(son[u]) dfs2(son[u],u,false),sn=son[u];
    update(u,fa,1);
    ans[u]=sum;
    sn=0;
    if(op) update(u,fa,-1),mx=0,sum=0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1,0);
    dfs2(1,0,true);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}