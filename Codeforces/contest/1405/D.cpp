#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
void dfs(int u,int fa) {
    mx[u]=dist[u];
    if(dist[u]>dist[mx]) mx=u;
    for(auto v:G[u]) {
        if(v==fa) continue;
        dist[v]=dist[u]+1;
        dfs(v,u);
    }
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].PB(v);
            G[v].PB(u);
        }
        for(int i=1;i<=n;i++) dist[i]=0;
        mx=0;
        dfs(b,0);
        if(dist[a]<=da) {puts("Alice");break;}
        if(dist[a]-da>=mx)
        int t=mx;
        for(int i=1;i<=n;i++) dist[i]=0;
        mx=0;
        dfs(t,0);
        if(dist[mx]>=)
        if(db>=da*2&&dist[mx]>=da*2)
    }
    return 0;
}