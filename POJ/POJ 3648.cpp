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
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(n==0&&m==0) break;
        init();
        for(int i=1;i<=m;i++) {
            int a,b;
            char c,d;
            scanf("%d%c%d%c",&a,&c,&b,&d);
            if(a==0) a=n;
            if(b==0) b=n;
            if(c=='h'&&d=='h') G[a].PB(b+n),G[b].PB(a+n);
            else if(c=='h'&&d=='w') G[a].PB(b),G[b+n].PB(a+n);
            else if(c=='w'&&d=='h') G[a+n].PB(b+n),G[b].PB(a);
            else G[a+n].PB(b),G[b+n].PB(a);
        }
        G[n<<1].PB(n);
        for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
        bool f=false;
        for(int i=1;i<=n;i++) if(c[i]==c[i+n]) {f=true;break;}
        if(f) puts("bad luck");
        else {
            for(int i=1;i<n;i++) {
                if(c[i]<c[i+n]) printf("%dw ",i);
                else printf("%dh ",i);
            }
            puts("");
        }
    }
    return 0;
}