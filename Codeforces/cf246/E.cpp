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
string s[N];
unordered_map<string,int>mp[N];
vi g[N];
vector<pii>q[N];
int n,m,depth[N],sz[N],son[N],ans[N],sum[N],sn;
void dfs(int u,int d) {
    depth[u]=d;
    sz[u]=1;
    for(auto v:g[u]) {
        depth[v]=depth[u]+1;
        dfs(v,d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void update(int u,int val) {
    if(!mp[depth[u]][s[u]]) sum[depth[u]]++;
    mp[depth[u]][s[u]]+=val;
    if(!mp[depth[u]][s[u]]) sum[depth[u]]--;
    for(auto v:g[u]) if(v!=sn) update(v,val);
}
void dsu(int u,bool op) {
    for(auto v:g[u]) if(v!=son[u]) dsu(v,true);
    if(son[u]) dsu(son[u],false),sn=son[u];
    update(u,1);
    for(auto x:q[u]) ans[x.se]=sum[depth[u]+x.fi];
    sn=0;
    if(op) update(u,-1);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        int fa;
        scanf("%d",&fa);
        g[fa].pb(i);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
        int x,d;
        scanf("%d%d",&x,&d);
        q[x].pb({d,i});
    }
    dfs(0,0);
    dsu(0,true);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}