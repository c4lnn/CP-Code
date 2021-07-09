#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,cnt,sz;
map<int,int> id;
bool f,st[N];
vector<int> G[N];
void dfs(int u,int pre) {
    sz++;
    st[u]=true;
    for(auto v:G[u]) {
        if(st[v]&&v!=pre) f=true;
        if(st[v]) continue;
        dfs(v,u);
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++) {
        scanf("%d",&n);
        int u,v;
        for(int i=1;i<=cnt;i++) G[i].clear();
        id.clear();
        cnt=0;
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&u,&v);
            if(!id.count(u)) id[u]=++cnt;
            if(!id.count(v)) id[v]=++cnt;
            G[id[u]].push_back(id[v]);
            G[id[v]].push_back(id[u]);
        }
        for(int i=1;i<=cnt;i++) st[i]=false;
        int res=0;
        for(int i=1;i<=cnt;i++) {
            if(!st[i]) {
                f=false;
                sz=0;
                dfs(i,0);
                if(f) res+=sz;
                else res+=sz-1;
            }
        }
        printf("Case #%d: %d\n",k,res);
    }
    return 0;
}