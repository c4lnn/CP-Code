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
const int N=205;
vector<int> G[N];
int n,m,cnt,dfn[N],low[N],top,stk[N],cnt_scc,c[N],id[N];
DB x1[N],x2[N],y1[N],y2[N];
bool ins[N];
void init() {
    for(int i=1;i<=n*2;i++) G[i].clear();
    cnt=cnt_scc=top=0;
    for(int i=1;i<=n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
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
DB judge(DB x1,DB y1,DB x2,DB y2,DB d) {
    DB dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    if(dist-d*d*4<1e-4) return true;
    return false;
}
bool check(DB mid) {
    init();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(judge(x1[i],y1[i],x1[j],y1[j],mid)) G[i].PB(j+n);
            if(judge(x1[i],y1[i],x2[j],y2[j],mid)) G[i].PB(j);
            if(judge(x2[i],y2[i],x1[j],y1[j],mid)) G[i+n].PB(j+n);
            if(judge(x2[i],y2[i],x2[j],y2[j],mid)) G[i+n].PB(j);
        }
    for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) if(c[i]==c[i+n]) return false;
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&x1[i],&y1[i],&x2[i],&y2[i]);
        DB l=0,r=10000;
        while(r-l>1e-4) {
            DB mid=(l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        printf("%.2f\n",l);
    }
    return 0;
}