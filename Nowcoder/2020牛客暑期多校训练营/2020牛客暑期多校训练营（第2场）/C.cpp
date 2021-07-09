#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,cnt[N],lf[N],tot;
vector<int> G[N];
void dfs(int u,int fa) {
    cnt[u]=0;
    for(auto v:G[u]) {
        if(v==fa) continue;
        dfs(v,u);
        cnt[u]++;
    }
    if(!cnt[u]||u==1&&cnt[u]==1) lf[++tot]=u;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v),G[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",tot+1>>1);
    for(int i=1;i<=tot/2;i++) printf("%d %d\n",lf[i],lf[tot-i+1]);
    if(tot&1) printf("%d %d\n",lf[tot/2+1],1);
    return 0;
}