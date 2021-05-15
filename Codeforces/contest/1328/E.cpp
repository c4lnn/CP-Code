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
const int N=2e5+5;
int n,m,k,cnt,d[N],fa[N],l[N],r[N],a[N];
VI g[N];
void dfs(int u) {
    l[u]=++cnt;
    for(auto v:g[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;
        d[v]=d[u]+1;
        dfs(v);
    }
    r[u]=++cnt;
}
bool check(int u,int v) {
    if(l[v]>l[u]&&r[v]<r[u]) return true;
    return false;
}
bool solve() {
    int t=0;
    for(int i=1;i<=k;i++)
        if(d[a[i]]>d[t])
            t=a[i];
    for(int i=1;i<=k;i++) {
        if(a[i]==t||a[i]==1) continue;
        if(!check(fa[a[i]],t)) return false;
    }
    return true;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1);
    for(int i=1;i<=m;i++) {
        scanf("%d",&k);
        for(int j=1;j<=k;j++) scanf("%d",&a[j]);
        puts(solve()?"YES":"NO");
    }
    return 0;
}