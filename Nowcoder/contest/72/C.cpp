#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int N=750005;
vector<int>g[N];
int fa[N],tot[N][3];
void dfs(int u) {
    for(auto v:g[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    for(int i=1;i<=q;i++) {
        int x;
        cin>>x;
        tot[x][1]++,tot[x][2]++;
        if(fa[fa[x]]) tot[fa[fa[x]]][0]++;
        if(fa[x]) tot[fa[x]][0]++,tot[fa[x]][1]++;
        else tot[x][0]++;
        cout<<tot[x][0]+tot[fa[x]][1]+tot[fa[fa[x]]][2]<<endl;
    }
    return 0;
}