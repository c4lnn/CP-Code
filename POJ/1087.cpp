#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=500;
int n,m,k,s,t,d[N],cur[N];
VI g[N];
VPII e;
map<string,int> mp;
void add_edge(int u,int v,int c) {
    e.PB(MP(v,c));
    e.PB(MP(u,0));
    g[u].PB(SZ(e)-2);
    g[v].PB(SZ(e)-1);
}
bool bfs() {
    for(int i=1;i<=n;i++) d[i]=0;
    queue<int> q;
    d[s]=1;
    q.push(s);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int i=0;i<SZ(g[u]);i++) {
            int v=e[g[u][i]].FI,c=e[g[u][i]].SE;
            if(d[v]||c<=0) continue;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    return d[t];
}
int dfs(int u,int a) {
    if(u==t) return a;
    int f,flow=0;
    for(int &i=cur[u];i<SZ(g[u]);i++) {
        int v=e[g[u][i]].FI,&c=e[g[u][i]].SE;
        if(d[v]!=d[u]+1||c<=0||(f=dfs(v,min(a,c)))<=0) continue;
        c-=f;
        e[g[u][i]^1].SE+=f;
        a-=f;
        flow+=f;
        if(!a) break;
    }
    return flow;
}
int dinic() {
    int flow=0;
    while(bfs()) {
        for(int i=1;i<=n;i++) cur[i]=0;
        flow+=dfs(s,0x3f3f3f3f);
    }
    return flow;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    s=1;
    t=2;
    string str;
    for(int i=1;i<=n;i++) {
        cin>>str;
        mp[str]=i;
    }
    scanf("%d",&m);
    for(int i=1;i<=n;i++) add_edge(t+i,t,1);
    for(int i=1;i<=m;i++) {
        cin>>str;
        cin>>str;
        if(!mp.count(str)) mp[str]=++n;
        add_edge(s,t+mp[str],1);
    }
    scanf("%d",&k);
    string tt;
    for(int i=1;i<=k;i++) {
        cin>>tt>>str;
        if(!mp.count(tt)) mp[tt]=++n;
        if(!mp.count(str)) mp[str]=++n;
        add_edge(t+mp[tt],t+mp[str],0x3f3f3f3f);
    }
    n=n+m+t;
    printf("%d\n",m-dinic());
    return 0;
}