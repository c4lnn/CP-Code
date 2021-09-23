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
int l[N],r[N];
VI g[N],t;
void dfs(int u,int fa) {
    t.PB(u);
    for(auto v:g[u]) if(v!=fa) {
        dfs(v,u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    while(cin>>n>>m) {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) l[i]=r[i]=i;
        for(int i=1;i<=m;i++) {
            int a,b;cin>>a>>b;
            if(r[b]&&r[a]) {
                g[r[b]].PB(r[a]);
                g[r[a]].PB(r[b]);
                r[b]=l[a];
            }
            else if(r[a]) r[b]=l[a],l[b]=r[a];
            l[a]=r[a]=0;
        }
        for(int i=1;i<=n;i++) {
            t.clear();
            if(r[i]) {
                dfs(r[i],0);
                cout<<SZ(t)<<' ';
                for(int j=0;j<SZ(t);j++) cout<<t[j]<<" \n"[j==SZ(t)-1];
            }
            else cout<<0<<'\n';
        }
    }
    return 0;
}