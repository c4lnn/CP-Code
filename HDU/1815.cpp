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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1005;
int dist_s1_s2,x1,y1,x2,y2,x[N],y[N],dist_s1[N],dist_s2[N];
int n,a,b,cnt,cnt_scc,top,dfn[N],low[N],c[N],stk[N];
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
    for(int i=1;i<=n*2;i++) g[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(dist_s1[i]+dist_s1[j]>mid) g[i].PB(j+n);
            if(dist_s1[i]+dist_s1_s2+dist_s2[j]>mid) g[i].PB(j);
            if(dist_s2[i]+dist_s1_s2+dist_s1[j]>mid) g[i+n].PB(j+n);
            if(dist_s2[i]+dist_s2[j]>mid) g[i+n].PB(j);
        }
    cnt=cnt_scc=top=0;
    for(int i=1;i<=n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
    for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) if(c[i]==c[i+n]) return false;
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&a,&b)) {
        for(int i=1;i<=n*2;i++) G[i].clear();
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        dist_s1_s2=abs(x1-x2)+abs(y1-y2);
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&x[i],&y[i]);
            dist_s1[i]=abs(x[i]-x1)+abs(y[i]-y1);
            dist_s2[i]=abs(x[i]-x2)+abs(y[i]-y2);
        }
        for(int i=1;i<=a;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].PB(v+n);
            G[v].PB(u+n);
            G[u+n].PB(v);
            G[v+n].PB(u);
        }
        for(int i=1;i<=b;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].PB(v);
            G[v].PB(u);
            G[u+n].PB(v+n);
            G[v+n].PB(u+n);
        }
        int l=0,r=9000000;
        while(l<r) {
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(l==9000000) puts("-1");
        else printf("%d\n",r);
    }
    return 0;
}