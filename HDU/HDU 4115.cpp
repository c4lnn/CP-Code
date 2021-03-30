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
const int N=20005;
int n,m,cnt,dfn[N],low[N],top,stk[N],cnt_scc,c[N],t[N];
bool ins[N];
VI G[N];
void init() {
    for(int i=1;i<=n*2;i++) G[i].clear();
    cnt=cnt_scc=top=0;
    for(int i=1;i<=n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
}
int check(int a,int b) {
    if(a==b) return 0;
    if(a==1&&b==2||a==2&&b==3||a==3&&b==1) return -1;
    return 1;
}
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    stk[++top]=u;
    ins[u]=true;
    for(auto v:G[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        ++cnt_scc;
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
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++) {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=n;i++) scanf("%d",&t[i]);
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            int x=check(t[u],t[v]);
            if(!w) {
                if(x==0) {
                    G[u].PB(v);
                    G[u+n].PB(v+n);
                    G[v].PB(u);
                    G[v+n].PB(u+n);
                }
                else if(x==1) {
                    G[u].PB(v+n);
                    G[u+n].PB(u);
                    G[v].PB(v+n);
                    G[v+n].PB(u);
                }
                else {
                    G[u].PB(u+n);
                    G[u+n].PB(v);
                    G[v].PB(u+n);
                    G[v+n].PB(v);
                }
            }
            else {
                if(x==0) {
                    G[u].PB(v+n);
                    G[u+n].PB(v);
                    G[v].PB(u+n);
                    G[v+n].PB(u);
                }
            }
        }
        for(int i=1;i<=2*n;i++) if(!dfn[i]) tarjan(i);
        bool f=false;
        for(int i=1;i<=n;i++) if(c[i]==c[i+n]) {f=true;break;}
        printf("Case #%d: ",cs);
        puts(f?"no":"yes");
    }
    return 0;
}
