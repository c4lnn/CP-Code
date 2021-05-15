#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=205;
int n,m,col[N],match[N];
bool st[N];
VI g[N];
bool dfs1(int u,int t) {
    col[u]=t;
    for(auto v:g[u]) {
        if(col[v]==3-t) continue;
        if(col[v]==t||!dfs1(v,3-t)) return false;
    }
    return true;
}
bool dfs2(int u) {
    for(auto v:g[u]) {
        if(st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs2(match[v])) {
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}
void solve() {
    for(int i=1;i<=n;i++) col[i]=0;
    for(int i=1;i<=n;i++) if(!col[i]&&!dfs1(i,1)) {puts("No");return;}
    for(int i=1;i<=n;i++) match[i]=-1;
    int res=0;
    for(int i=1;i<=n;i++) {
        if(match[i]!=-1) continue;
        for(int j=1;j<=n;j++) st[j]=false;
        if(dfs2(i)) res++;
    }
    printf("%d\n",res);
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].PB(v);
            g[v].PB(u);
        }
        solve();
    }
    return 0;
}