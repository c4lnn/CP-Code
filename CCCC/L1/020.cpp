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
const int N=1e5+5;
bool vis[N],f[N];
int main() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int k;cin>>k;
        for(int j=1;j<=k;j++) {
            int x;cin>>x;
            if(k==1) continue;
            f[x]=true;
        }
    }
    int m;cin>>m;
    VI res;
    for(int i=1;i<=m;i++) {
        int x;cin>>x;
        if(vis[x]) continue;
        vis[x]=true;
        if(!f[x]) res.PB(x);
    }
    if(SZ(res)) for(int i=0;i<SZ(res);i++) printf("%05d%c",res[i],i==SZ(res)-1?'\n':' ');
    else cout<<"No one is handsome\n";
    return 0;
}