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
int a[1005][105];
set<PII> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    if(k) for(int i=1;i<=n;i++) reverse(a[i]+1,a[i]+1+m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int k=j+1;k<=m;k++) if(a[i][j]>a[i][k]) {
                swap(a[i][j],a[i][k]);
                s.emplace(j,k);
            }
        }
    }
    cout<<SZ(s)<<'\n';
    if(!k) for(auto x:s) cout<<x.FI<<' '<<x.SE<<'\n';
    else for(auto x:s) cout<<m-x.FI+1<<' '<<m-x.SE+1<<'\n';
    return 0;
}