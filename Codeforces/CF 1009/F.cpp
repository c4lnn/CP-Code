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
const int N=1e6+5;
vi g[N];
int *f[N],temp[N],*now=temp,n,dep[N],len[N],son[N],ans[N];
void dfs(int u,int fa) {
    dep[u]=dep[fa]+1;
    for(auto v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        if(len[v]>len[son[u]]) son[u]=v;
    }
    len[u]=len[son[u]]+1;
}
void dp(int u,int fa) {
    if(son[u]) f[son[u]]=f[u]+1,dp(son[u],u),ans[u]=ans[son[u]]+1;
    f[u][0]=1;
    for(auto v:g[u]) {
        if(v==son[u]||v==fa) continue;
        f[v]=now;
        now+=len[v];
        dp(v,u);
        for(int i=1;i<=len[v];i++) {
            f[u][i]+=f[v][i-1];
            if(f[u][i]>f[u][ans[u]]||f[u][i]==f[u][ans[u]]&&i<ans[u]) ans[u]=i;
        }
    }
    if(f[u][ans[u]]==1) ans[u]=0;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    f[1]=now,now+=len[1];
    dp(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}