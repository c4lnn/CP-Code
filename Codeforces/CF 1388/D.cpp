#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,b[N],res[N],cnt;
long long a[N],tot;
vector<int> G[N],t;
void dfs(int u,int fa) {
    for(auto v:G[u]) dfs(v,u);
    if(a[u]>0) res[++cnt]=u,tot+=a[u],a[fa]+=a[u];
    else t.push_back(u);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) {
        if(b[i]==-1) continue;
        G[b[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) if(b[i]==-1) dfs(i,0);
    for(int i=t.size()-1;i>=0;i--) res[++cnt]=t[i],tot+=a[t[i]];
    printf("%lld\n",tot);
    for(int i=1;i<=n;i++) printf("%d ",res[i]);
    puts("");
    return 0;
}