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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=1e5+5;
string s;
int m,pre[N],id[N],res[N],tr[N][26],fail[N],sz[N],dfn[N],a[N],cnt,dfn_cnt;
VI g[N];
VPII q[N];
void insert() {
    int u=0,t=0;
    for(auto c:s) {
        if(c=='B') u=pre[u];
        else if(c=='P') id[++t]=u;
        else {
            if(!tr[u][c-'a']) tr[u][c-'a']=++cnt;
            pre[tr[u][c-'a']]=u;
            u=tr[u][c-'a'];
        }
    }
}
void build() {
    queue<int> q;
    for(int i=0;i<26;i++) if(tr[0][i]) g[0].PB(tr[0][i]),q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<26;v++) {
            if(tr[u][v]) {
                fail[tr[u][v]]=tr[fail[u]][v];
                g[tr[fail[u]][v]].PB(tr[u][v]);
                q.push(tr[u][v]);
            }
            else tr[u][v]=tr[fail[u]][v];
        }
    }
}
void dfs(int u) {
    dfn[u]=++dfn_cnt;
    sz[dfn[u]]=1;
    for(auto v:g[u]) {
        dfs(v);
        sz[dfn[u]]+=sz[dfn[v]];
    }
}
void update(int x,int v) {
    for(int i=x;i<=dfn_cnt;i+=i&-i) a[i]+=v;
}
int query(int l,int r) {
    int ret=0;
    for(int i=r;i;i-=i&-i) ret+=a[i];
    for(int i=l-1;i;i-=i&-i) ret-=a[i];
    return ret;
}
void solve() {
    int u=0;
    for(auto c:s) {
        if(c=='B') {
            if(u) update(dfn[u],-1);
            u=pre[u];
        }
        else if(c=='P') {
            for(auto x:q[u]) {
                res[x.SE]=query(dfn[x.FI],dfn[x.FI]+sz[dfn[x.FI]]-1);
            }
        }
        else {
            u=tr[u][c-'a'];
            if(u) update(dfn[u],1);
        }
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    insert();
    build();
    dfs(0);
    cin>>m;
    for(int i=1;i<=m;i++) {
        int x,y;cin>>x>>y;
        q[id[y]].EB(id[x],i);
    }
    solve();
    return 0;
}