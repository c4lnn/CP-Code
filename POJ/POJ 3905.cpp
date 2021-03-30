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
int n,m,cnt,cnt_scc,top,dfn[N],low[N],c[N],stk[N];
bool ins[N];
VI G[N];
void init() {
    cnt=cnt_scc=top=0;
    for(int i=1;i<=n*2;i++) {
        G[i].clear();
        dfn[i]=low[i]=c[i]=0;
        ins[i]=false;
    }
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
    while(~scanf("%d%d",&n,&m)) {
        init();
        for(int i=1;i<=m;i++) {
            int a,b;
            char c,d;
            scanf(" %c%d %c%d",&c,&a,&d,&b);
            if(c=='+'&&d=='+') {
                G[a].PB(b+n);
                G[b].PB(a+n);
            }
            else if(c=='-'&&d=='-') {
                G[a+n].PB(b);
                G[b+n].PB(a);
            }
            else if(c=='+'&&d=='-') {
                G[a].PB(b);
                G[b+n].PB(a+n);
            }
            else {
                G[a+n].PB(b+n);
                G[b].PB(a);
            }
        }
        for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
        bool f=false;
        for(int i=1;i<=n;i++) if(c[i]==c[i+n]) {f=true;break;}
        puts(f?"0":"1");
    }
    return 0;
}