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
const int N=2005;
int n,m,cnt,cnt_scc,top,stk[N],dfn[N],low[N],c[N];
bool ins[N];
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        char opt[4];
        scanf("%d%d%d%s",&u,&v,&w,opt);
        u++,v++;
        if(opt[0]=='A') {
            if(w==0) {
                G[u+n].PB(v);
                G[v+n].PB(u);
            }
            else {
                G[u].PB(u+n);
                G[v].PB(v+n);
            }
        }
        else if(opt[0]=='O') {
            if(w==0) {
                G[u+n].PB(u);
                G[v+n].PB(v);
            }
            else {
                G[u].PB(v+n);
                G[v].PB(u+n);
            }
        }
        else {
            if(w==0) {
                G[u].PB(v);
                G[u+n].PB(v+n);
                G[v].PB(u);
                G[v+n].PB(v+n);
            }
            else {
                G[u].PB(v+n);
                G[v].PB(u+n);
            }
        }
    }
    for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++)
        if(c[i]==c[i+n]) {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}