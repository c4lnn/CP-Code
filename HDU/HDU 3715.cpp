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
const int N=405;
const int M=10005;
vector<int> G[N];
int n,m,cnt,dfn[N],low[N],top,stk[N],cnt_scc,c[N];
int a[M],b[M],d[M];
bool ins[N];
void init() {
    for(int i=0;i<n*2;i++) G[i].clear();
    cnt=cnt_scc=top=0;
    for(int i=0;i<n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
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
bool check(int mid) {
    init();
    for(int i=1;i<=mid;i++) {
        if(d[i]==0) {
            G[a[i]<<1].PB((b[i]<<1)+1);
            G[b[i]<<1].PB((a[i]<<1)+1);
        }
        else if(d[i]==1) {
            G[a[i]<<1].PB(b[i]<<1);
            G[(a[i]<<1)+1].PB((b[i]<<1)+1);
            G[b[i]<<1].PB(a[i]<<1);
            G[(b[i]<<1)+1].PB((a[i]<<1)+1);
        }
        else {
            G[(a[i]<<1)+1].PB(b[i]<<1);
            G[(b[i]<<1)+1].PB(a[i]<<1);
        }
    }
    for(int i=0;i<2*n;i++) if(!dfn[i]) tarjan(i);
    for(int i=0;i<n;i++) if(c[i<<1]==c[(i<<1)+1]) return false;
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i],&b[i],&d[i]);
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