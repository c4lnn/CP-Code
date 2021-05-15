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
const int N=2e5+5;
int n,m,in[N],w[N],mn[N];
VI g[N];
int topo() {
    queue<int> q;
    for(int i=1;i<=n;i++) if(!in[i]) mn[i]=w[i],q.push(i);
    int res=INT_MIN;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            mn[v]=min(mn[v],mn[u]);
            if(--in[v]==0) {
                res=max(res,w[v]-mn[v]);
                mn[v]=min(mn[v],w[v]);
                q.push(v);
            }
        }
    }
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        ++in[v];
    }
    memset(mn,0x3f,sizeof mn);
    cout<<topo()<<'\n';
    return 0;
}