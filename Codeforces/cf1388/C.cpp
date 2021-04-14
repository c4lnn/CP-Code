#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],h[N],p[N];
vector<int> G[N];
bool dfs(int u,int fa) {
    for(auto v:G[u]) {
        if(v==fa) continue;
        if(dfs(v,u)==false) return false;
        a[u]+=a[v],p[u]+=p[v];
    }
    if((p[u]+h[u]-a[u])&1) return false;
    int x=(h[u]+p[u]-a[u])/2;
    if(x<0||p[u]-x<0) return false;
    a[u]+=x,p[u]-=x;
    return true;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        for(int i=1;i<=n;i++) G[i].clear(),a[i]=0;
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(dfs(1,0)) puts("YES");
        else puts("NO");
    }
    return 0;
}