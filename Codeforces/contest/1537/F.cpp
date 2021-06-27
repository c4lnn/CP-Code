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
const int N=2e5+5;
int col[N],a[N],b[N];
VI g[N];
void init(int n) {
    for(int i=1;i<=n;i++) {
        col[i]=-1;
        g[i].clear();
    }
}
bool dfs(int u,int t) {
    col[u]=t;
    for(auto v:g[u]) {
        if(col[v]==t) return false;
        else if(col[v]==-1) if(!dfs(v,t^1)) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        init(n);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=m;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v),g[v].PB(u);
        }
        LL sum=0;
        for(int i=1;i<=n;i++) sum+=b[i]-a[i];
        if(sum&1) cout<<"NO"<<'\n';
        else {
            bool f=false;
            for(int i=1;i<=n;i++) if(col[i]==-1) {
                if(!dfs(i,0)) {f=true;break;}
            }
            if(f) cout<<"YES"<<'\n';
            else {
                LL sum[2];
                sum[0]=sum[1]=0;
                for(int i=1;i<=n;i++) sum[col[i]]+=b[i]-a[i];
                cout<<(sum[0]==sum[1]?"YES":"NO")<<'\n';
            }
        }
    }
    return 0;
}