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
const LL MOD1=1e9+7,MOD2=1e9+9;
const int N=2005;
int tot[N],c[N],a[N][N],rt;
LL power1[N],power2[N];
bool st[N];
VI g[N];
void dfs(int u,int fa) {
    ++tot[c[u]];
    a[rt][u]=a[rt][fa]+(tot[c[u]]==1);
    for(auto v:g[u]) if(v!=fa&&!st[v]) {
        st[v]=true;
        dfs(v,u);
    }
    --tot[c[u]];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    power1[0]=power2[0]=1;
    for(int i=1;i<=2000;i++) {
        power1[i]=power1[i-1]*19560929%MOD1;
        power2[i]=power2[i-1]*19560929%MOD2;
    }
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            g[i].clear();
        }
        for(int i=2;i<=n;i++) {
            int x;cin>>x;
            g[i].PB(x);
            g[x].PB(i);
        }
        for(int i=1;i<=n;i++) cin>>c[i];
        for(rt=1;rt<=n;rt++) {
            for(int i=1;i<=n;i++) st[i]=false;
            dfs(rt,0);
        }
        for(int i=1;i<=n;i++) {
            LL aa=0,bb=0;
            for(int j=1;j<=n;j++) {
                aa=(aa+a[i][j]*power1[j-1]%MOD1)%MOD1;
                bb=(bb+a[i][j]*power2[j-1]%MOD2)%MOD2;
            }
            cout<<aa<<' '<<bb<<'\n';
        }
    }
    return 0;
}