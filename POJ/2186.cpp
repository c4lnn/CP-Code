#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
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
const int N=10005;
int n,m,cnt,cnt_scc,top,stk[N],dfn[N],low[N],c[N],sz[N],in[N],tot[N];
bool ins[N];
VI G[N],g[N];
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    stk[++top]=u;
    ins[u]=true;
    for(int i=0;i<SZ(G[u]);i++) {
        int v=G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        cnt_scc++;
        int x;
        do {
            x=stk[top--];
            ins[x]=false;
            c[x]=cnt_scc;
            sz[cnt_scc]++;
        } while(u!=x);
    }
}
void topo() {
    queue<int> q;
    for(int i=1;i<=cnt_scc;i++) tot[i]=1;
    for(int i=1;i<=cnt_scc;i++) if(!in[i]) q.push(i);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i];
            tot[v]+=tot[u];
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(v);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++)
        for(int j=0;j<SZ(G[i]);j++) {
            int u=c[i],v=c[G[i][j]];
            if(u==v) continue;
            g[u].PB(v);
            in[v]++;
        }
    topo();
    int res=0;
    for(int i=1;i<=cnt_scc;i++) if(tot[i]==cnt_scc) res+=sz[i];
    printf("%d\n",res);
    return 0;
}