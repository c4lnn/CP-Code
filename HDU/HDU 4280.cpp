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
const int N=1e5+5;
int n,m,s,t,cur[N],d[N];
int head[N],nxt[N<<1],cnt;
PII e[N<<1];
void add_edge(int u,int v,int c) {
    e[cnt]=MP(v,c);
    nxt[cnt]=head[u];
    head[u]=cnt++;
}
bool bfs() {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    d[s]=1;
    q.push(s);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=nxt[i]) {
            int v=e[i].FI,c=e[i].SE;
            if(d[v]||c<=0) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    return d[t];
}
int dfs(int u,int a) {
    if(u==t) return a;
    int flow=0,f;
    for(int &i=cur[u];i!=-1;i=nxt[i]) {
        int v=e[i].FI,&c=e[i].SE;
        if(d[v]!=d[u]+1||c<=0||(f=dfs(v,min(a,c)))<=0) continue;
        c-=f;
        e[i^1].SE+=f;
        a-=f;
        flow+=f;
        if(!a) break;
    }
    return flow;
}
LL dinic() {
    LL flow=0;
    while(bfs()) {
        for(int i=1;i<=n;i++) cur[i]=head[i];
        flow+=dfs(s,0x3f3f3f3f);
    }
    return flow;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        int mn=0x3f3f3f3f,mx=0xc0c0c0c0;
        for(int i=1;i<=n;i++) head[i]=-1;
        cnt=0;
        for(int i=1;i<=n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x<mn) mn=x,s=i;
            if(x>mx) mx=x,t=i;
        }
        for(int i=1;i<=m;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
            add_edge(v,u,c);
        }
        printf("%lld\n",dinic());
    }
    return 0;
}