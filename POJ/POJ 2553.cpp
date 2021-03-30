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
const int N=5005;
int n,m,cnt,cnt_scc,top,stk[N],dfn[N],low[N],c[N];
bool ins[N],st[N];
VI G[N];
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
        } while(u!=x);
    }
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d",&n)&&n) {
        for(int i=1;i<=n;i++) G[i].clear();
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].PB(v);
        }
        cnt=cnt_scc=top=0;
        for(int i=1;i<=n;i++) dfn[i]=low[i]=c[i]=0,ins[i]=st[i]=false;
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
        for(int u=1;u<=n;u++)
            for(int i=0;i<SZ(G[u]);i++) {
                int v=G[u][i];
                if(c[u]==c[v]) continue;
                st[c[u]]=true;
            }
        for(int i=1;i<=n;i++) {
            if(st[c[i]]) continue;
            printf("%d ",i);
        }
        puts("");
    }
    return 0;
}