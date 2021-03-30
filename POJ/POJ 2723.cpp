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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=5000;
int n,m,cnt,cnt_scc,top,dfn[N],low[N],c[N],stk[N],a[N],b[N];
bool ins[N];
VI G[N],g[N];
void init() {
    cnt=cnt_scc=top=0;
    for(int i=0;i<n<<1;i++) g[i].clear(),dfn[i]=low[i]=c[i]=0,ins[i]=false;
}
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
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i];
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
        } while(u!=x);
    }
}
bool check(int mid) {
    init();
    for(int i=1;i<=mid;i++) {
        g[a[i]+n].PB(b[i]);
        g[b[i]+n].PB(a[i]);
    }
    for(int i=0;i<n<<1;i++) if(!dfn[i]) tarjan(i);
    for(int i=0;i<n;i++) if(c[i]==c[i+n]) return false;
    return true;
}
int main() {
    while(~scanf("%d%d",&n,&m)&&n+m) {
        n<<=1;
        for(int i=0;i<n<<1;i++) G[i].clear();
        for(int i=0;i<n>>1;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].PB(y+n);
            G[y].PB(x+n);
        }
        for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
        int l=0,r=m;
        while(l<r) {
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}