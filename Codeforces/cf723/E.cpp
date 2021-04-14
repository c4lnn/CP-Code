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
//head
const int N=205;
int n,m,cnt,head[N],to[N*N],nxt[N*N],d[N];
bool st[N*N],f[N];
VPII res;
void add_edge(int u,int v) {
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
void init() {
    for(int i=1;i<=n+1;i++) head[i]=0,f[i]=false;
    for(int i=1;i<=n;i++) d[i]=0;
    for(int i=2;i<=cnt;i++) st[i]=0;
    cnt=1;
    res.clear();
}
void hierholzer(int s) {
    stack<int> stk;
    stk.push(s);
    while(SZ(stk)) {
        int u=stk.top(),i=head[u];
        while(i&&st[i]) i=nxt[i];
        if(i) {
            stk.push(to[i]);
            st[i]=st[i^1]=true;
            f[to[i]]=f[to[i^1]]=true;
            if(to[i^1]!=n+1&&to[i]!=n+1) res.EB(to[i],to[i^1]);
            head[u]=nxt[i];
        }
        else stk.pop();
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        init();
        cin>>n>>m;
        for(int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            add_edge(u,v);
            add_edge(v,u);
            ++d[u],++d[v];
        }
        int tot=0;
        for(int i=1;i<=n;i++) if(d[i]&1) ++tot,add_edge(i,n+1),add_edge(n+1,i);
        for(int i=1;i<=n+1;i++) if(!f[i]) hierholzer(i);
        cout<<n-tot<<'\n';
        for(auto x:res) cout<<x.FI<<' '<<x.SE<<'\n';
    }
    return 0;
}