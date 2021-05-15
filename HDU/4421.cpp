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
const int N=1005;
int n,tot,cnt,cnt_scc,top,dfn[N],low[N],c[N],stk[N],b[N][N];
bool ins[N];
vector<int> G[N];
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
        cnt_scc++;
        int x;
        do {
            x=stk[top--];
            ins[x]=false;
            c[x]=cnt_scc;
        } while(u!=x);
    }
}
bool solve() {
    for(int k=0;k<31;k++) {
        cnt=cnt_scc=top=0;
        for(int i=1;i<=n*2;i++) {
            G[i].clear();
            dfn[i]=low[i]=c[i]=0;
            ins[i]=false;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) {
                    if(b[i][j]) return false;
                    continue;
                }
                if(b[i][j]!=b[j][i]) return false;
                int t=(1<<k)&b[i][j];
                if(i%2==0&&j%2==0) {
                    if(t) G[i].PB(j+n);
                    else G[i+n].PB(i);
                }
                else if(i%2==1&&j%2==1) {
                    if(t) G[i].PB(i+n);
                    else G[i+n].PB(j);
                }
                else {
                    if(t) G[i].PB(j+n),G[i+n].PB(j);
                    else G[i].PB(j),G[i+n].PB(j+n);
                }
            }
        }
        for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
        for(int i=1;i<=n;i++) if(c[i]==c[i+n]) return false;
    }
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&b[i][j]);
        puts(solve()?"YES":"NO");
    }
    return 0;
}
