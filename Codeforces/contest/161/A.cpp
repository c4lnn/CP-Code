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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x,y;cin>>n>>m>>x>>y;
    VI a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    VPII res;
    for(int i=1,j=1;i<=n&&j<=m;) {
        if(a[i]+y<b[j]) ++i;
        else if(a[i]-x>b[j]) ++j;
        else {
            res.EB(i,j);
            ++i,++j;
        }
    }
    cout<<SZ(res)<<'\n';
    for(auto x:res) cout<<x.FI<<' '<<x.SE<<'\n';
    return 0;
}