#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,p[N],cnt,vis[N],res[N];
int m;
vector<int> v[N];
void find_cycle(int x) {
    if(vis[x]) return;
    vis[x]=cnt;
    v[cnt].push_back(x);
    find_cycle(p[x]);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        ++cnt;
        find_cycle(i);
        int sz=v[cnt].size(),inv;
        for(int j=0;j<sz;j++) if(1ll*m*j%sz==1) {inv=j;break;}
        for(int j=0;j<sz;j++) res[v[cnt][j]]=v[cnt][(j+inv)%sz];
    }
    for(int i=1;i<=n;i++) printf("%d ",res[i]);
    puts("");
    return 0;
}