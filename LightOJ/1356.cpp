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
const int N=40005;
const int M=500005;
int n,a[N],match[N],dep[N],id[M],mn[M];
VI p,g[N],v1,v2;
void add_edge(int u,int v) {
    g[u].PB(v);
    g[v].PB(u);
}
void get_prime() {
    for(int i=2;i<=M;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>M) break;
            mn[i*x]=x;
        }
    }
}
int get_factor(int x) {
    int t=x,tot=0;
    for(int i=0;i<SZ(p);i++) {
        if(p[i]*p[i]>t) break;
        if(t%p[i]==0) {
            if(id[x/p[i]]) add_edge(id[x/p[i]],id[x]);
            while(t%p[i]==0) {
                ++tot;
                t/=p[i];
            }
        }
    }
    if(t>1) {
        ++tot;
        if(id[x/t]) add_edge(id[x/t],id[x]);
    }
    return tot;
}
bool bfs() {
    queue<int> q;
    for(int i=1;i<=n;i++) dep[i]=0;
    for(auto x:v1) if(match[x]==-1) dep[x]=1,q.push(x);
    bool f=false;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(dep[v]) continue;
            dep[v]=dep[u]+1;
            if(match[v]==-1) f=true;
            else dep[match[v]]=dep[v]+1,q.push(match[v]);
        }
    }
    return f;
}
bool dfs(int u) {
    for(auto v:g[u]) {
        if(dep[v]!=dep[u]+1) continue;
        dep[v]=0;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int hk() {
    for(int i=1;i<=n;i++) match[i]=-1;
    int res=n;
    while(bfs()) for(int i=1;i<=n;i++) if(match[i]==-1&&dfs(i)) res--;
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    get_prime();
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        v1.clear(),v2.clear();
        memset(id,0,sizeof id);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) {
            int x;
            scanf("%d",&a[i]);
            id[a[i]]=i;
        }
        for(int i=1;i<=n;i++) {
            if(get_factor(a[i])&1) v1.PB(i);
            else v2.PB(i);
        }
        printf("Case %d: %d\n",cs,hk());
    }
    return 0;
}