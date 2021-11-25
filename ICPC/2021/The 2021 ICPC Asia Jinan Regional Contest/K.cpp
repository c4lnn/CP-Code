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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=105;
VI g[N];
LL sum,step;
void dfs(int u,int fa) {
    for(auto v:g[u]) if(v!=fa) {
        ++step;
        sum+=step;
        dfs(v,u);
        ++step;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) g[i].clear();
        step=sum=0;
        for(int i=1;i<n;i++) {
            int u,v;cin>>u>>v;
            g[u].PB(v);
            g[v].PB(u);
        }
        dfs(1,0);
        cout<<fixed<<setprecision(10)<<1.0*sum/(n-1)<<'\n';
    }
    return 0;
}