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
const LL INF=0x3f3f3f3f3f3f3f3f;
const int N=1e3+5;
const int M=1e4+5;
int n,m,s,t,a[M],b[M];
LL L,c[M],dist[N][2];
bool st[N],f[M];
VPII g[N];
struct R {
    LL w;
    int u;
    R() {}
    R(LL w,int u):w(w),u(u) {}
    bool operator < (const R &T) const {
        return w>T.w;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>L>>s>>t;
    ++s,++t;
    for(int i=1;i<=m;i++) {
        cin>>a[i]>>b[i]>>c[i];
        ++a[i],++b[i];
        g[a[i]].EB(b[i],i);
        g[b[i]].EB(a[i],i);
        if(!c[i]) c[i]=1,f[i]=true;
    }
    for(int i=1;i<=n;i++) dist[i][0]=dist[i][1]=INF;
    priority_queue<R> q;
    q.emplace(0,s);
    dist[s][0]=dist[s][1]=0;
    while(SZ(q)) {
        int u=q.top().u;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.FI;
            LL w=c[x.SE];
            if(!st[v]&&dist[u][0]+w<dist[v][0]) {
                dist[v][0]=dist[u][0]+w;
                q.emplace(dist[v][0],v);
            }
        }
    }
    LL diff=L-dist[t][0];
    if(diff<0) return cout<<"NO"<<'\n',0;
    for(int i=1;i<=n;i++) st[i]=false;
    q.emplace(0,s);
    while(SZ(q)) {
        int u=q.top().u;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.FI;
            LL &w=c[x.SE];
            if(f[x.SE]) {
                if(dist[u][1]+w<dist[v][0]+diff) w=dist[v][0]+diff-dist[u][1];
            }
            if(!st[v]&&dist[u][1]+w<dist[v][1]) {
                dist[v][1]=dist[u][1]+w;
                q.emplace(dist[v][1],v);
            }
        }
    }
    if(dist[t][1]==L) {
        cout<<"YES"<<'\n';
        for(int i=1;i<=m;i++) cout<<a[i]-1<<' '<<b[i]-1<<' '<<c[i]<<'\n';
    }
    else cout<<"NO"<<'\n';
    return 0;
}