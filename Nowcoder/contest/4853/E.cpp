#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
//head
const int N=100010;
vi G[N];
int n,k,len[N],dep[N],son[N];
ll a[N],ans[N],temp[N<<1],*f[N],*g[N],*now=temp;
void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    for(auto v:G[u]) {
        if(v==fa) continue;
        dfs(v,u);
        if(len[v]>len[son[u]]) son[u]=v;
    }
    len[u]=len[son[u]]+1;
}
void dp(int u,int fa) {
    if(son[u]) f[son[u]]=f[u]+1,g[son[u]]=g[u]+1,dp(son[u],u);
    f[u][0]=1;
    g[u][0]=a[u];
    for(auto v:G[u]) {
        if(v==fa||v==son[u]) continue;
        f[v]=now,now+=len[v];
        g[v]=now,now+=len[v];
        dp(v,u);
        for(int i=1;i<k&&i<len[u];i++) {
            if(k-i-1>=len[v]) continue;
            ans[u]+=f[u][i]*g[v][k-i-1]+g[u][i]*f[v][k-i-1];
        }
        for(int i=1;i<=len[v];i++) f[u][i]+=f[v][i-1],g[u][i]+=g[v][i-1];
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,0);
    f[1]=now,now+=len[1];
    g[1]=now,now+=len[1];
    dp(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    puts("");
    return 0;
}
